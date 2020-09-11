/*
[abc152] F - Tree and Constraints
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 50;
const int MAX_M = 20;

int N;
int M;
int u[MAX_M], v[MAX_M];
vector<int> g[MAX_N];
int dep[MAX_N], par[MAX_N];
int lca[MAX_M];

void dfs0(int v, int p = -1, int d = 0) {
    dep[v] = d, par[v] = p;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs0(to, v, d + 1);
    }
}

int calc_lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    while (dep[u] > dep[v]) {
        u = par[u];
    }
    while (u != v) {
        u = par[u], v = par[v];
    }
    return u;
}

void dfs1(vector<int> &s, int v, int p = -1) {
    for (int to : g[v]) {
        if (to == p) continue;
        dfs1(s, to, v);
        s[v] += s[to];
    }
}

int calc(int pat) {
    vector<int> s(N);
    for (int j = 0; j < M; j++) {
        if ((pat >> j) & 1) {
            s[u[j]]++, s[v[j]]++;
            s[lca[j]] -= 2;
        }
    }
    dfs1(s, 0);
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] > 0) ret++;
    }
    return ret;
}

int sz(int pat) {
    int ret = 0;
    for (; pat > 0; pat >>= 1) {
        if (pat & 1) ret++;
    }
    return ret;
}

ll solve() {
    dfs0(0);
    for (int j = 0; j < M; j++) {
        lca[j] = calc_lca(u[j], v[j]);
    }

    ll ans = 0;
    for (int pat = 1; pat < (1 << M); pat++) {
        int c = calc(pat);
        ans += (sz(pat) % 2 == 1 ? 1LL : -1LL) * (1LL << (N - 1 - c));
    }
    ans = (1LL << (N - 1)) - ans;

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    cin >> M;
    for (int j = 0; j < M; j++) {
        cin >> u[j] >> v[j];
        u[j]--, v[j]--;
    }

    cout << solve() << endl;

    return 0;
}
