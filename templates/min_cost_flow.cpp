// min_cost_flow.cpp
// 最小費用流を求める
// グラフは隣接リスト型

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_V = 10000;
const ll INF = 1e18;

struct edge {
    int to, cap;
    ll cost;
    int rev;
};

class Graph {
public:
    void add_edge(int from, int to, int cap, ll cost) {
        g[from].push_back((edge){to, cap, cost, (int)g[to].size()});
        g[to].push_back((edge){from, 0, -cost, (int)g[from].size() - 1});
        return;
    }
    ll min_cost_flow(int s, int t, int f) {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            que;
        // first: tmp min distance, second: vertex index
        pair<ll, int> p;
        int d;
        ll cost = 0;

        memset(h, 0, sizeof(h));
        while (f > 0) {
            fill(dist, dist + MAX_V, INF);
            dist[s] = 0;
            que.push(pair<ll, int>(0, s));
            while (!que.empty()) {
                p = que.top();
                que.pop();
                int v = p.second;
                if (dist[v] < p.first) {
                    continue;
                }
                for (int i = 0; i < (int)g[v].size(); i++) {
                    edge e = g[v][i];
                    if (e.cap > 0 &&
                        dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        pre_v[e.to] = v;
                        pre_e[e.to] = i;
                        que.push(pair<ll, int>(dist[e.to], e.to));
                    }
                }
            }
            if (dist[t] >= INF) {
                return -1;
            }

            for (int v = 0; v < MAX_V; v++) {
                h[v] = min(INF, h[v] + dist[v]);
            }

            d = f;
            for (int v = t; v != s; v = pre_v[v]) {
                d = min(d, g[pre_v[v]][pre_e[v]].cap);
            }
            f -= d;
            cost += h[t] * d;
            for (int v = t; v != s; v = pre_v[v]) {
                edge &e = g[pre_v[v]][pre_e[v]];
                e.cap -= d;
                g[v][e.rev].cap += d;
            }
        }
        return cost;
    }

private:
    vector<edge> g[MAX_V];
    ll h[MAX_V];
    ll dist[MAX_V];
    int pre_v[MAX_V], pre_e[MAX_V];
};

int main() { return 0; }
