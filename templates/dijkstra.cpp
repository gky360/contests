// dijkstra.cpp
// ダイクストラ法(有向グラフ用)
// グラフは隣接リスト型

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define MAX_V 1000
#define INF 100000000
using namespace std;


typedef pair<int, int> PAIR;


class Graph {
public:
  void add_edge(int from, int to, int cost); // 有向辺を追加
  void dijkstra(int s);
  int dist[MAX_V];
  int V; // ←初期化忘れずに
private:
  vector<PAIR> g[MAX_V]; // cost, to
};

void Graph::add_edge(int from, int to, int cost) {
  g[from].push_back(PAIR(cost, to));
  return;
}

void Graph::dijkstra(int s) {
  priority_queue<PAIR, vector<PAIR>, greater<PAIR> > q;
  PAIR p, e;

  fill(dist, dist + V, INF);
  dist[s] = 0;
  q.push(PAIR(dist[s], s));
  while(!q.empty()){
    p = q.top();
    q.pop();
    if (dist[p.second] < p.first) {
      continue;
    }
    for (int i = 0; i < (int)g[p.second].size(); i++) {
      e = g[p.second][i];
      if (dist[e.second] > dist[p.second] + e.first) {
        dist[e.second] = dist[p.second] + e.first;
        q.push(PAIR(dist[e.second], e.second));
      }
    }
  }
  return;
}


int main() {


  return 0;

}


