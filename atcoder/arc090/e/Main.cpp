// ARC090
// E - Avoiding Collision

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;
const int MAX_M = 200000;
const int MAX_V = MAX_N;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

class Graph {
public:
    ll dist[MAX_V];
    vector<pli> g[MAX_V];  // cost, to
    void add_edge(int from, int to, ll cost);
    void dijkstra(int s);
};

void Graph::add_edge(int from, int to, ll cost) {
    g[from].push_back(pli(cost, to));
    return;
}

void Graph::dijkstra(int s) {
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

int N, M;
int S, T;
Graph g;
vector<int> dps, dpt;

void calc_dp(int s, bool rev, vector<int>& dp) {
    vector<int> idx(N);
    ll k = (rev ? -1 : 1);

    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&](int a, int b) { return k * g.dist[a] < k * g.dist[b]; });

    dp.resize(N);
    dp[s] = 1;
    for (int u : idx) {
        for (auto e : g.g[u]) {
            ll cost = e.first;
            int v = e.second;
            if (g.dist[u] + k * cost == g.dist[v]) {
                (dp[v] += dp[u]) %= MOD;
            }
        }
    }
}

ll mul_v(int u, int v) {
    ll tmp = 1;
    (tmp *= 1LL * dps[u] * dps[u] % MOD) %= MOD;
    (tmp *= 1LL * dpt[v] * dpt[v] % MOD) %= MOD;
    return tmp;
}

int main() {
    cin >> N >> M;
    cin >> S >> T;
    S--;
    T--;
    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        g.add_edge(u - 1, v - 1, d);
        g.add_edge(v - 1, u - 1, d);
    }
    g.dijkstra(S);

    calc_dp(S, false, dps);
    calc_dp(T, true, dpt);

    for (int i = 0; i < N; i++) {
        cerr << dps[i] << ", ";
    }
    cerr << endl;
    for (int i = 0; i < N; i++) {
        cerr << dpt[i] << ", ";
    }
    cerr << endl;

    ll ans_e = 0;
    for (int u = 0; u < N; u++) {
        for (auto e : g.g[u]) {
            ll cost = e.first;
            int v = e.second;
            if ((g.dist[u] + cost == g.dist[v]) && 2 * g.dist[u] < g.dist[T] &&
                2 * g.dist[v] > g.dist[T]) {
                (ans_e += mul_v(u, v)) %= MOD;
            }
        }
    }

    ll ans_v = 0;
    for (int v = 0; v < N; v++) {
        if (2 * g.dist[v] == g.dist[T]) {
            (ans_v += mul_v(v, v)) %= MOD;
        }
    }

    ll ans = (1LL * dps[T] * dps[T] - ans_e + MOD - ans_v + MOD) % MOD;
    cout << ans << endl;

    return 0;
}
