// dijkstra.cpp
// ダイクストラ法(有向グラフ用)
// グラフは隣接リスト型

#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef long long int ll;
typedef pair<ll, int> pli;

const int MAX_V = 10000;
const ll INF = 1e18;

class Graph {
public:
    ll dist[MAX_V];
    vector<pli> g[MAX_V];  // cost, to
    void add_edge(int from, int to, ll cost) {
        g[from].push_back(pli(cost, to));
        return;
    }
    void dijkstra(int s) {
        priority_queue<pli, vector<pli>, greater<pli>> q;
        pli p, e;

        fill(dist, dist + MAX_V, INF);
        dist[s] = 0;
        q.push(pli(dist[s], s));
        while (!q.empty()) {
            p = q.top();
            q.pop();
            if (dist[p.second] < p.first) {
                continue;
            }
            for (int i = 0; i < (int)g[p.second].size(); i++) {
                e = g[p.second][i];
                if (dist[e.second] > dist[p.second] + e.first) {
                    dist[e.second] = dist[p.second] + e.first;
                    q.push(pli(dist[e.second], e.second));
                }
            }
        }
        return;
    }
};

int main() { return 0; }
