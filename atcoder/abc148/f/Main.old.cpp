/*
[abc148] F - Playing Tag on Tree
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5 + 5;
const int MAX_V = MAX_N;
const int MAX_LOG_V = 32;

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

void init(int root) {
    dfs_lca(root);
    for (int k = 1; k < MAX_LOG_V; k++) {
        for (int v = 0; v < MAX_V; v++) {
            par[k][v] = (par[k - 1][v] < 0) ? -1 : par[k - 1][par[k - 1][v]];
        }
    }
}

int N;
int TK, AO;

ll solve() {
    init(AO);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int w = lca(i, TK);
        if (dep[w] > dep[TK] - dep[w]) {
            ans = max(ans, dep[i] - 1);
        }
    }

    return ans;
}

int main() {
    cin >> N >> TK >> AO;
    TK--, AO--;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    cout << solve() << endl;

    return 0;
}
