/*
[agc034] D - Manhattan Max Matching
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1000;
const int MAX_V = 2 * MAX_N + 4 + 2;
const ll P = 1e9 * 4 + 1;
const ll INF = 1e18;

struct edge {
    int to, cap;
    ll cost;
    int rev;
};

class Graph {
public:
    void add_edge(int from, int to, int cap, ll cost);
    ll min_cost_flow(int s, int t, int f);

private:
    vector<edge> g[MAX_V];
    ll h[MAX_V];
    ll dist[MAX_V];
    int pre_v[MAX_V], pre_e[MAX_V];
};

void Graph::add_edge(int from, int to, int cap, ll cost) {
    g[from].push_back((edge){to, cap, cost, (int)g[to].size()});
    g[to].push_back((edge){from, 0, -cost, (int)g[from].size() - 1});
    return;
}

ll Graph::min_cost_flow(int s, int t, int f) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
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

int N;
ll X[2][MAX_N], Y[2][MAX_N], C[2][MAX_N];
Graph g;

ll solve() {
    int S = accumulate(C[0], C[0] + N, 0);
    int s = 2 * N + 4, t = 2 * N + 4 + 1;
    for (int i = 0; i < N; i++) {
        g.add_edge(s, i, C[0][i], 0);
        g.add_edge(0 + i, 2 * N + 0, S, P - (+X[0][i] + Y[0][i]));
        g.add_edge(0 + i, 2 * N + 1, S, P - (-X[0][i] + Y[0][i]));
        g.add_edge(0 + i, 2 * N + 2, S, P - (+X[0][i] - Y[0][i]));
        g.add_edge(0 + i, 2 * N + 3, S, P - (-X[0][i] - Y[0][i]));
        g.add_edge(2 * N + 0, N + i, S, P - (-X[1][i] - Y[1][i]));
        g.add_edge(2 * N + 1, N + i, S, P - (+X[1][i] - Y[1][i]));
        g.add_edge(2 * N + 2, N + i, S, P - (-X[1][i] + Y[1][i]));
        g.add_edge(2 * N + 3, N + i, S, P - (+X[1][i] + Y[1][i]));
        g.add_edge(N + i, t, C[1][i], 0);
    }
    ll cost = g.min_cost_flow(s, t, S);
    return P * 2LL * S - cost;
}

int main() {
    cin >> N;
    for (int rb = 0; rb < 2; rb++) {
        for (int i = 0; i < N; i++) {
            cin >> X[rb][i] >> Y[rb][i] >> C[rb][i];
        }
    }

    cout << solve() << endl;

    return 0;
}
