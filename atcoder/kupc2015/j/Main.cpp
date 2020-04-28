/*
[kupc2015] J - MODクエリ
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

int N, Q;
int A[MAX_N];

vector<int> g[MAX_V];
int par[MAX_LOG_V][MAX_V];
int mm[MAX_LOG_V][MAX_V];
int dep[MAX_V];

void dfs_lca(int v, int p = -1, int d = 0) {
    par[0][v] = p;
    mm[0][v] = A[v];
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
            mm[k][v] = (par[k - 1][v] < 0)
                           ? mm[k - 1][v]
                           : min(mm[k - 1][v], mm[k - 1][par[k - 1][v]]);
        }
    }
}

ll solve(int x, int v, int w) {
    int t = lca(v, w);
    for (int u = v; u >= 0 && dep[u] >= dep[t];) {
        x %= A[u];
        for (int k = MAX_LOG_V - 1; u >= 0 && k >= 0; k--) {
            if (mm[k][u] > x) {
                u = par[k][u];
            }
        }
    }
    for (int u = t; dep[u] <= dep[w];) {
        x %= A[u];
        int s = w;
        int l = -1, lk = -1;
        for (int k = MAX_LOG_V - 1; k >= 0; k--) {
            if (par[k][s] >= 0 && dep[par[k][s]] >= dep[u]) {
                if (mm[k][s] <= x) l = s, lk = k;
                s = par[k][s];
            }
        }
        if (l == -1) break;
        s = l;
        for (int k = lk - 1; k >= 0; k--) {
            if (mm[k][par[k][s]] <= x) s = par[k][s];
        }
        u = s;
    }

    return x;
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int b, c;
        cin >> b >> c;
        g[b - 1].push_back(c - 1);
        g[c - 1].push_back(b - 1);
    }
    init_lca(0);
    for (int i = 0; i < Q; i++) {
        int x, v, w;
        cin >> x >> v >> w;
        v--, w--;
        cout << solve(x, v, w) << endl;
    }

    return 0;
}
