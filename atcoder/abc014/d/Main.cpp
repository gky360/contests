/*
[abc014] D - 閉路
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MAX_V = 1e5;
const int MAX_LOG_V = 18;

int N;
int Q;

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

ll solve(int a, int b) {
    int v = lca(a, b);
    return dep[a] + dep[b] - 2 * dep[v] + 1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
    init_lca(0);
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << solve(a, b) << endl;
    }

    return 0;
}
