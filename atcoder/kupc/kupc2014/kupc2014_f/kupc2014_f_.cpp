// 京都大学プログラミングコンテスト 2014 F - テレパシー

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define MAX_N 1000
#define MAX_V (MAX_N * 2 + 1)
#define INF 100000000
#define EPS 1e-10
using namespace std;


typedef pair<int, int> P;

struct edge{
  int to, cap, cost, rev;
};

class Graph{
  public:
    void add_edge(int from, int to, int cap, int cost);
    int min_cost_flow(int s, int t, int f);
  private:
    vector<edge> g[MAX_V];
    int h[MAX_V];
    int dist[MAX_V];
    int pre_v[MAX_V], pre_e[MAX_V];
};

void Graph::add_edge(int from, int to, int cap, int cost){
  g[from].push_back((edge){to, cap, cost, g[to].size()});
  g[to].push_back((edge){from, 0, -cost, g[from].size() - 1});
  return;
}

int Graph::min_cost_flow(int s, int t, int f){
  priority_queue<P, vector<P>, greater<P> > que;
  // first:仮の最短距離, second:頂点index
  P p;
  int d;
  int cost = 0;
  int v;
  int i;

  memset(h, 0, sizeof(h));
  while(f > 0){
    fill(dist, dist + MAX_V, INF);
    dist[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
      p = que.top();
      que.pop();
      v = p.second;
      if(dist[v] < p.first){
        continue;
      }
      for(i = 0; i < (int)g[v].size(); i++){
        edge e = g[v][i];
        if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          pre_v[e.to] = v;
          pre_e[e.to] = i;
          que.push(P(dist[e.to], e.to));
        }
      }
    }
    if(dist[t] >= INF){
      return -1;
    }

    for(v = 0; v < MAX_V; v++){
      h[v] = min(INF, h[v] + dist[v]);
    }

    d = f;
    for(v = t; v != s; v = pre_v[v]){
      d = min(d, g[pre_v[v]][pre_e[v]].cap);
    }
    f -= d;
    cost += h[t] * d;
    for(v = t; v != s; v = pre_v[v]){
      edge &e = g[pre_v[v]][pre_e[v]];
      e.cap -= d;
      g[v][e.rev].cap += d;
    }
  }
  return cost;
}


int N;
int x[MAX_N], y[MAX_N], d[MAX_N];
int ans;

int main(){

  Graph graph;
  int cap, sum;
  int c, u, v;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }

  const int S = 2 * N - 1;
  const int T = 2 * N;
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &d[i], &c);
    graph.add_edge(i, T, INF, c);
  }

  sum = 0;
  for (int i = 0; i < N - 1; i++) {
    scanf("%d%d", &u, &v);
    u--; v--;

    cap = (int)ceil(-d[u] - d[v] + sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v])) - EPS);
    sum += cap;
    graph.add_edge(S, N + i, cap, 0);
    graph.add_edge(N + i, u, INF, 0);
    graph.add_edge(N + i, v, INF, 0);
  }

  ans = graph.min_cost_flow(S, T, sum);

  printf("%d\n", ans);

  return 0;

}


