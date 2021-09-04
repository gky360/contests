/*
[arc108] C - Keep Graph Connected
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
const int MAX_M = 2e5;

class UnionFind {
public:
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : (data[x] = root(data[x])); }
    int size(int x) { return -data[root(x)]; }
};

int N, M;
int u[MAX_M], v[MAX_M], c[MAX_M];
vector<pii> g[MAX_N];
int ans[MAX_N];

void dfs(int v, int par = -1) {
    for (auto [x, to] : g[v]) {
        if (to == par) continue;
        ans[to] = (ans[v] == x) ? (x % N + 1) : x;
        dfs(to, v);
    }
}

void solve() {
    UnionFind uf(N);
    REP(i, M) {
        if (!uf.same(u[i], v[i])) {
            uf.unite(u[i], v[i]);
            g[u[i]].push_back({c[i], v[i]});
            g[v[i]].push_back({c[i], u[i]});
        }
    }
    if (uf.size(0) != N) {
        cout << "No" << endl;
        return;
    }

    ans[0] = 1;
    dfs(0);

    REP(i, N) cout << ans[i] << endl;
}

int main() {
    cin >> N >> M;
    REP(i, M) cin >> u[i] >> v[i] >> c[i], u[i]--, v[i]--;

    solve();

    return 0;
}
