// AtCoder Regular Contest 061
// E - すぬけ君の地下鉄旅行 / Snuke's Subway Trip

#include <cstdio>
#include <unordered_map>
#include <queue>
#include <utility>
#include <functional>
#define MAX_N 100000
#define MAX_C 1000000
#define INF 100000000
#define S 0
#define T (N - 1)
#define ARR 0 // arrival 到着
#define DEP 1 // departure 出発
#define TRS 2 // transfer 乗換
using namespace std;


typedef long long int ll;
typedef pair<int, ll> PAIR;


class Graph {
public:
  void add_edge(ll from, ll to, int cost); // 有向辺を追加
  void dijkstra(ll s);
  ll count_at(ll s);
  unordered_map<ll, int> dist;
private:
  unordered_map<ll, vector<PAIR> > g; // cost, to
};

void Graph::add_edge(ll from, ll to, int cost) {
  g[from].push_back(PAIR(cost, to));
  return;
}

void Graph::dijkstra(ll s) {
  priority_queue<PAIR, vector<PAIR>, greater<PAIR> > q;
  PAIR p, e;

  dist.clear();
  dist[s] = 0;
  q.push(PAIR(dist[s], s));
  while(!q.empty()){
    p = q.top();
    q.pop();
    if (dist[p.second] == 0 && p.second != s) {
      dist[p.second] = INF;
    }
    if (dist[p.second] < p.first) {
      continue;
    }
    for (ll i = 0; i < (ll)g[p.second].size(); i++) {
      e = g[p.second][i];
      if (dist[e.second] == 0 && e.second != s) {
        dist[e.second] = INF;
      }
      if (dist[e.second] > dist[p.second] + e.first) {
        dist[e.second] = dist[p.second] + e.first;
        q.push(PAIR(dist[e.second], e.second));
      }
    }
  }
  return;
}

ll Graph::count_at(ll s) {
  return g[s].size();
}



int N, M;
Graph G;
int ans;

ll to_index(int n, int c, int type) {
  return (ll)n * (MAX_C * 2 + 1) + type * MAX_C + (type == TRS ? 0 : c);
}

void one_way_connect(int from, int to, int c) {
  ll s_dep, t_arr;
  s_dep = to_index(from, c, DEP);
  t_arr = to_index(to, c, ARR);

  // 駅 n における鉄道会社 c の最初の路線を作成するとき
  // 駅内の edge を新設
  if (G.count_at(s_dep) == 0) {
    G.add_edge(to_index(from, c, TRS), s_dep, 1);
  }
  if (G.count_at(t_arr) == 0) {
    G.add_edge(t_arr, to_index(to, c, TRS), 0);
    G.add_edge(t_arr, to_index(to, c, DEP), 0);
  }

  G.add_edge(s_dep, t_arr, 0);
}

int main() {

  int p, q, c;

  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d", &p, &q, &c);
    p--; q--; c--;
    one_way_connect(p, q, c);
    one_way_connect(q, p, c);
  }

  G.dijkstra(to_index(S, -1, TRS));

  ans = G.dist[to_index(T, -1, TRS)];
  if (ans == INF || (ans == 0 && S != T)) {
    ans = -1;
  }
  printf("%d\n", ans);

  return 0;

}


