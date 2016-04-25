// AtCoder Indeedなう（オープンコンテストB）
// D - Game on a Grid

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define MAX_W 100
#define MAX_H 100
#define MAX_V (MAX_W * MAX_H)
using namespace std;


typedef pair<int, int> PAIR; // first: cost, second: v_index

class Graph
{
public:
  void add_edge(int from, int to, int cost);
  int prim(); // 最小全域木のコストを返す。グラフが連結でない場合は0を返す。
  int V;
private:
  vector<PAIR> g[MAX_V];
};

void Graph::add_edge(int from, int to, int cost)
{
  g[from].push_back(PAIR(cost, to));
  return;
}

int Graph::prim()
{
  priority_queue<PAIR, vector<PAIR>, greater<PAIR> > q;
  bool used[MAX_V];
  int cost;
  PAIR p; // first: cost, second: v_index
  int v;
  int n;
  int i;

  memset(used, 0, sizeof(used));
  q.push(PAIR(0, 0));
  cost = 0;
  n = 0;
  while(!q.empty()){
    p = q.top();
    q.pop();
    v = p.second;
    if(used[v]){
      continue;
    }
    used[v] = true;
    cost += p.first;
    n++;
    for(i = 0; i < (int)g[v].size(); i++){
      if(!used[g[v][i].second]){
        q.push(g[v][i]);
      }
    }
  }
  if(n < V){
    return 0;
  }
  return cost;
}

int H, W;
int sx, sy, gx, gy;
int p[MAX_W][MAX_H];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
Graph G;
int ans;

int main() {

  int x, y;

  scanf("%d%d", &H, &W);
  scanf("%d%d", &sx, &sy);
  scanf("%d%d", &gx, &gy);
  ans = 0;
  for (int j = 0; j < H; j++) {
    for (int i = 0; i < W; i++) {
      scanf("%d", &p[i][j]);
      ans += p[i][j];
    }
  }

  for (int j = 0; j < H; j++) {
    for (int i = 0; i < W; i++) {
      for (int k = 0; k < 4; k++) {
        x = i + dx[k];
        y = j + dy[k];
        if (x < 0 || W <= x || y < 0 || H <= y) {
          continue;
        }
        G.add_edge(W * j + i, W * y + x, - p[i][j] * p[x][y]);
      }
    }
  }
  ans += -G.prim();

  printf("%d\n", ans);

  return 0;
}


