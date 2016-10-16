// min_cost_flow.cpp
// 最小費用流を求める
// グラフは隣接リスト型

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define MAX_V 100
#define INF 100000000
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

void Graph::add_edge(int from, int to, int cap, int cost) {
  g[from].push_back((edge){to, cap, cost, g[to].size()});
  g[to].push_back((edge){from, 0, -cost, g[from].size() - 1});
  return;
}

int Graph::min_cost_flow(int s, int t, int f) {
  priority_queue<P, vector<P>, greater<P> > que;
  // first:仮の最短距離, second:頂点index
  P p;
  int d;
  int cost = 0;
  int v;
  int i;

  memset(h, 0, sizeof(h));
  while (f > 0) {
    fill(dist, dist + MAX_V, INF);
    dist[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
      p = que.top();
      que.pop();
      v = p.second;
      if (dist[v] < p.first) {
        continue;
      }
      for (i = 0; i < (int)g[v].size(); i++) {
        edge e = g[v][i];
        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          pre_v[e.to] = v;
          pre_e[e.to] = i;
          que.push(P(dist[e.to], e.to));
        }
      }
    }
    if (dist[t] >= INF) {
      return -1;
    }

    for (v = 0; v < MAX_V; v++) {
      h[v] = min(INF, h[v] + dist[v]);
    }

    d = f;
    for (v = t; v != s; v = pre_v[v]) {
      d = min(d, g[pre_v[v]][pre_e[v]].cap);
    }
    f -= d;
    cost += h[t] * d;
    for (v = t; v != s; v = pre_v[v]) {
      edge &e = g[pre_v[v]][pre_e[v]];
      e.cap -= d;
      g[v][e.rev].cap += d;
    }
  }
  return cost;
}


int main(){
  return 0;
}

