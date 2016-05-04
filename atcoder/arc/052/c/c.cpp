// AtCoder Regular Contest 052
// C - 高橋くんと不思議な道

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <functional>
#define MAX_N 10000
#define MAX_M 100000
#define MAX_V MAX_N
#define INF 1000000000
using namespace std;


typedef pair<int, int> PAIR; // cost, to
typedef pair<PAIR, int> PII;

int N, M;

class Graph {
public:
  void add_edge(int from, int to, int cost);
  void dijkstra_map(int s);
  int dist[MAX_V];
  int V;  // ←初期化忘れずに
private:
  vector<PAIR> g[MAX_V];
};

void Graph::add_edge(int from, int to, int cost) {
  g[from].push_back(PAIR(cost, to));
  return;
}

void Graph::dijkstra_map(int s) {
  map<int, int> dist_m[MAX_V]; // b, d
  map<int, int>::iterator itr;
  priority_queue<PII, vector<PII>, greater<PII> > q; // d, b, v
  PII p;
  PAIR e;
  int d, b, v, cost;

  fill(dist, dist + V, INF);
  dist[s] = 0;
  dist_m[s][0] = 0;
  q.push(make_pair(make_pair(0, 0), s));
  while (!q.empty()) {
    p = q.top();
    q.pop();
    d = p.first.first;
    b = p.first.second;
    v = p.second;
    if (dist_m[v][b] < d) {
      continue;
    }
    itr = dist_m[v].lower_bound(b);
    if (itr-- != dist_m[v].begin() && itr->second <= d) {
      continue;
    }
    for (int i = 0; i < (int)g[v].size(); i++) {
      e = g[v][i];
      cost = d + (e.first == 0 ? 1 : b + 1);
      if (e.second != s && dist_m[e.second][b + e.first] == 0) {
        dist_m[e.second][b + e.first] = INF;
      }
      if (dist_m[e.second][b + e.first] > cost) {
        dist_m[e.second][b + e.first] = cost;
        q.push(make_pair(make_pair(cost, b + e.first), e.second));
        if (dist[e.second] > cost) {
          dist[e.second] = cost;
        }
      }
    }
  }
}

Graph G;

int main() {

  int a, b, c;

  scanf("%d%d", &N, &M);
  G.V = N;
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d", &c, &a, &b);
    G.add_edge(a, b, c);
    G.add_edge(b, a, c);
  }

  G.dijkstra_map(0);

  for (int i = 0; i < N; i++) {
    printf("%d\n", G.dist[i]);
  }

  return 0;

}


