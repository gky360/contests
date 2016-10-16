// Kyoto University Programming Contest 2016
// E - 柵 / Fences

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_H 100
#define MAX_W 100
#define MAX_V (MAX_H * MAX_W * 2 + 2)
#define INF 100000000
using namespace std;


struct edge{
  int to, cap, rev; // 行き先, 容量, 逆辺番号
};

class Graph{
public:
  void add_edge(int from, int to, int cap);
  int max_flow(int s, int t);
private:
  void bfs(int s);
  int dfs(int v, int t, int f);
private:
  vector<edge> g[MAX_V];
  int level[MAX_V];
  int iter[MAX_V];
};

void Graph::add_edge(int from, int to, int cap) {
  g[from].push_back((edge){to, cap, (int)g[to].size()});
  g[to].push_back((edge){from, 0, (int)g[from].size() - 1});
  return;
}

int Graph::max_flow(int s, int t) {
  int f;
  int flow = 0;

  while (true) {
    bfs(s);
    if (level[t] < 0) {
      break;
    }
    memset(iter, 0, sizeof(iter));
    while ((f = dfs(s, t, INF)) > 0) {
      flow += f;
    }
  }
  return flow;
}

void Graph::bfs(int s) {
  queue<int> que;
  int v;
  int i;

  memset(level, -1, sizeof(level));
  level[s] = 0;
  que.push(s);
  while (!que.empty()) {
    v = que.front();
    que.pop();
    for (i = 0; i < (int)g[v].size(); i++) {
      if (g[v][i].cap > 0 && level[g[v][i].to] < 0) {
        level[g[v][i].to] = level[v] + 1;
        que.push(g[v][i].to);
      }
    }
  }
  return;
}

int Graph::dfs(int v, int t, int f) {
  int d;

  if (v == t) {
    return f;
  }
  for ( ; iter[v] < (int)g[v].size(); iter[v]++) {
    edge &e = g[v][iter[v]];
    if (e.cap > 0 && level[v] < level[e.to]) {
      d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}


int H, W;
Graph G;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
const int S = MAX_H * MAX_W * 2 + 0;
const int T = MAX_H * MAX_W * 2 + 1;
int ans;

int main() {

  int y, x;
  char buff[MAX_W + 2];

  scanf("%d%d", &H, &W);
  for (int i = 0; i < H; i++) {
    scanf("%s", buff);
    for (int j = 0; j < W; j++) {
      if (buff[j] == 'X') {
        G.add_edge(S, (i * W + j) * 2 + 0, INF);
        G.add_edge((i * W + j) * 2 + 0, (i * W + j) * 2 + 1, INF);
      } else {
        G.add_edge((i * W + j) * 2 + 0, (i * W + j) * 2 + 1, 1);
      }
      for (int k = 0; k < 4; k++) {
        y = i + dy[k];
        x = j + dx[k];
        if (y < 0 || H <= y || x < 0 || W <= x) {
          G.add_edge((i * W + j) * 2 + 1, T, INF);
        } else {
          G.add_edge((i * W + j) * 2 + 1, (y * W + x) * 2 + 0, INF);
        }
      }
    }
  }

  ans = G.max_flow(S, T);
  ans = ans >= INF ? -1 : ans;
  printf("%d\n", ans);

  return 0;

}


