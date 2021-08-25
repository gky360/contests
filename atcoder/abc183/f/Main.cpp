/*
[abc183] F - Confluence
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

const int MAX_N = 2e5;
const int MAX_Q = 2e5;

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

int N, Q;
vector<int> C;
vector<int> t, a, b;

void solve() {
    UnionFind uf(N);
    vector<unordered_map<int, int>> s(N);

    REP(i, N) s[i][C[i]] = 1;
    REP(q, Q) {
        if (t[q] == 1) {
            int x = uf.root(a[q]), y = uf.root(b[q]);
            if (x == y) continue;
            uf.unite(x, y);
            if (y == uf.root(y)) swap(x, y);
            for (auto [c, n] : s[y]) s[x][c] += n;
        } else {
            cout << s[uf.root(a[q])][b[q]] << endl;
        }
    }
}

int main() {
    cin >> N >> Q;
    C.resize(N), t.resize(Q), a.resize(Q), b.resize(Q);
    REP(i, N) cin >> C[i], C[i]--;
    REP(q, Q) cin >> t[q] >> a[q] >> b[q], a[q]--, b[q]--;

    solve();

    return 0;
}
