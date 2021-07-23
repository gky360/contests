/*
[past202010-open] M - 筆塗り
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MAX_Q = 1e5;
const int MAX_V = MAX_N;
const int MAX_LOG_V = 18;

int N, Q;
int u[MAX_Q], v[MAX_Q], c[MAX_Q];
vector<pii> g[MAX_V];
int par[MAX_LOG_V][MAX_V];
int pe[MAX_V];
int dep[MAX_V];
int ans[MAX_N - 1];

void dfs_lca(int v, int p = -1, int d = 0) {
    par[0][v] = p;
    dep[v] = d;
    for (auto [to, e] : g[v]) {
        if (to == p) {
            pe[v] = e;
        } else {
            dfs_lca(to, v, d + 1);
        }
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int k = 0; k < MAX_LOG_V; k++) {
        if (((dep[v] - dep[u]) >> k) & 1) v = par[k][v];
    }
    if (u == v) return u;
    for (int k = MAX_LOG_V - 1; k >= 0; k--) {
        if (par[k][u] != par[k][v]) {
            u = par[k][u];
            v = par[k][v];
        }
    }
    return par[0][u];
}

void init_lca(int root) {
    dfs_lca(root);
    for (int k = 1; k < MAX_LOG_V; k++) {
        for (int v = 0; v < MAX_V; v++) {
            par[k][v] = (par[k - 1][v] < 0) ? -1 : par[k - 1][par[k - 1][v]];
        }
    }
}

class UnionFind {
public:
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (dep[y] < dep[x]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : (data[x] = root(data[x])); }
    int size(int x) { return -data[root(x)]; }
};

void check(int s, int t, int cc, UnionFind &uf) {
    s = uf.root(s), t = uf.root(t);
    for (int v = s; v != t; v = uf.root(par[0][v])) {
        if (ans[pe[v]] >= 0) continue;
        ans[pe[v]] = cc;
        int p = par[0][v];
        uf.unite(v, p);
    }
}

void solve() {
    UnionFind uf(N);

    init_lca(0);

    memset(ans, -1, sizeof(ans));
    for (int q = Q - 1; q >= 0; q--) {
        int m = lca(u[q], v[q]);
        check(u[q], m, c[q], uf);
        check(v[q], m, c[q], uf);
    }

    REP(i, N - 1) {
        if (ans[i] < 0) ans[i] = 0;
        cout << ans[i] << endl;
    }
}

int main() {
    cin >> N >> Q;
    REP(i, N - 1) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back({b - 1, i});
        g[b - 1].push_back({a - 1, i});
    }
    REP(q, Q) cin >> u[q] >> v[q] >> c[q], u[q]--, v[q]--;

    solve();

    return 0;
}
