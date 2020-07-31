/*
[past201912-open] K - 巨大企業 / Conglomerate
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 150000;
const int MAX_Q = 100000;

const int MAX_V = MAX_N;
const int MAX_LOG_V = 18;

vector<int> g[MAX_V];
int par[MAX_LOG_V][MAX_V];
int dep[MAX_V];

void dfs_lca(int v, int p = -1, int d = 0) {
    par[0][v] = p;
    dep[v] = d;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs_lca(to, v, d + 1);
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

void init_lca(int root) {
    dfs_lca(root);
    for (int k = 1; k < MAX_LOG_V; k++) {
        for (int v = 0; v < MAX_V; v++) {
            par[k][v] = (par[k - 1][v] < 0) ? -1 : par[k - 1][par[k - 1][v]];
        }
    }
}

int N;
int p[MAX_N];
int Q;
int a[MAX_Q], b[MAX_Q];

void solve() {
    int root = -1;
    for (int i = 0; i < N; i++) {
        if (p[i] == -1) {
            root = i;
        } else {
            g[i].push_back(p[i]);
            g[p[i]].push_back(i);
        }
    }

    init_lca(root);

    for (int q = 0; q < Q; q++) {
        bool ans = lca(a[q], b[q]) == b[q];
        cout << (ans ? "Yes" : "No") << endl;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        if (p[i] != -1) {
            p[i]--;
        }
    }
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        cin >> a[q] >> b[q];
        a[q]--, b[q]--;
    }

    solve();

    return 0;
}
