// Kyoto University Programming Contest 2016
// B - 作問委員会 / Problem Committee

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_N 10000
#define MAX_K 26
#define MAX_C MAX_N
#define MAX_P 10
#define MAX_V (MAX_N + MAX_K + MAX_C + 2)
#define S (MAX_N + MAX_K + MAX_C + 0)
#define T (MAX_N + MAX_K + MAX_C + 1)
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

void Graph::add_edge(int from, int to, int cap){
  g[from].push_back((edge){to, cap, (int)g[to].size()});
  g[to].push_back((edge){from, 0, (int)g[from].size() - 1});
  return;
}

int Graph::max_flow(int s, int t){
  int f;
  int flow = 0;

  while(true){
    bfs(s);
    if(level[t] < 0){
      break;
    }
    memset(iter, 0, sizeof(iter));
    while((f = dfs(s, t, INF)) > 0){
      flow += f;
    }
  }
  return flow;
}

void Graph::bfs(int s){
  queue<int> que;
  int v;
  int i;

  memset(level, -1, sizeof(level));
  level[s] = 0;
  que.push(s);
  while(!que.empty()){
    v = que.front();
    que.pop();
    for(i = 0; i < (int)g[v].size(); i++){
      if(g[v][i].cap > 0 && level[g[v][i].to] < 0){
        level[g[v][i].to] = level[v] + 1;
        que.push(g[v][i].to);
      }
    }
  }
  return;
}

int Graph::dfs(int v, int t, int f){
  int d;

  if(v == t){
    return f;
  }
  for( ; iter[v] < (int)g[v].size(); iter[v]++){
    edge &e = g[v][iter[v]];
    if(e.cap > 0 && level[v] < level[e.to]){
      d = dfs(e.to, t, min(f, e.cap));
      if(d > 0){
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}


int N, K, C;
int initial[MAX_K];

int main() {

  int l, r, m, sum_initial;
  char buff[MAX_P + 2];

  scanf("%d%d", &N, &K);
  C = N / K;
  memset(initial, 0, sizeof(initial));
  for (int i = 0; i < N; i++) {
    scanf("%s", buff);
    initial[buff[0] - 'A']++;
  }

  l = 0; r = C + 1;
  while (r - l > 1) {
    Graph G;

    m = (l + r) / 2;
    for (int i = 0; i < m; i++) {
      G.add_edge(S, N + MAX_K + i, K);
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < MAX_K; j++) {
        G.add_edge(N + MAX_K + i, N + j, 1);
      }
    }
    sum_initial = 0;
    for (int i = 0; i < MAX_K; i++) {
      for (int j = sum_initial; j < sum_initial + initial[i]; j++) {
        G.add_edge(N + i, j, 1);
      }
      sum_initial += initial[i];
    }
    for (int i = 0; i < N; i++) {
      G.add_edge(i, T, 1);
    }

    if (G.max_flow(S, T) == K * m) {
      l = m;
    } else {
      r = m;
    }
  }

  printf("%d\n", l);

  return 0;

}


