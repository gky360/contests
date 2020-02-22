/*
[abc133] F - Colorful Tree
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int MAX_Q = 1e5;

const int MAX_V = MAX_N;
const int MAX_LOG_V = 18;

struct edge {
    int d;
    int c;
    int to;
};

int N, Q;
vector<edge> g[MAX_N];
vector<int> req[MAX_N];
int X[MAX_Q], Y[MAX_Q], U[MAX_Q], V[MAX_Q];
int W[MAX_Q];
int dist[MAX_N];
int cur_num[MAX_N], cur_sum[MAX_N];
map<int, int> num[MAX_N], sum[MAX_N];

int par[MAX_LOG_V][MAX_V];
int dep[MAX_V];

void dfs(int v, int p = -1, int d = 0) {
    par[0][v] = p;
    dep[v] = d;
    for (auto& e : g[v]) {
        if (e.to == p) {
            continue;
        }
        dfs(e.to, v, d + 1);
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) {
        swap(u, v);
    }
    for (int k = 0; k < MAX_LOG_V; k++) {
        if (((dep[v] - dep[u]) >> k) & 1) {
            v = par[k][v];
        }
    }
    if (u == v) {
        return u;
    }
    for (int k = MAX_LOG_V - 1; k >= 0; k--) {
        if (par[k][u] != par[k][v]) {
            u = par[k][u];
            v = par[k][v];
        }
    }
    return par[0][u];
}

void init() {
    dfs(0);
    for (int k = 1; k < MAX_LOG_V; k++) {
        for (int v = 0; v < N; v++) {
            par[k][v] = (par[k - 1][v] < 0) ? -1 : par[k - 1][par[k - 1][v]];
        }
    }
}

void dfs2(int v, int par = -1) {
    for (int c : req[v]) {
        num[v][c] = cur_num[c];
        sum[v][c] = cur_sum[c];
    }

    for (auto& e : g[v]) {
        if (e.to == par) {
            continue;
        }
        dist[e.to] = dist[v] + e.d;
        cur_num[e.c]++;
        cur_sum[e.c] += e.d;
        dfs2(e.to, v);
        cur_num[e.c]--;
        cur_sum[e.c] -= e.d;
    }
}

int calc(int v, int x, int y) { return dist[v] - sum[v][x] + y * num[v][x]; }

void solve() {
    init();
    for (int i = 0; i < Q; i++) {
        W[i] = lca(U[i], V[i]);
        req[U[i]].push_back(X[i]);
        req[V[i]].push_back(X[i]);
        req[W[i]].push_back(X[i]);
    }

    dfs2(0);

    for (int i = 0; i < Q; i++) {
        int ans = calc(U[i], X[i], Y[i]) + calc(V[i], X[i], Y[i]) -
                  2 * calc(W[i], X[i], Y[i]);
        cout << ans << endl;
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--;
        g[a].push_back((edge){d, c, b});
        g[b].push_back((edge){d, c, a});
    }
    for (int i = 0; i < Q; i++) {
        cin >> X[i] >> Y[i] >> U[i] >> V[i];
        X[i]--, U[i]--, V[i]--;
    }

    solve();

    return 0;
}
