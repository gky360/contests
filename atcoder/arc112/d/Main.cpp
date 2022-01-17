/*
[arc112] D - Skate
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

int H, W;
vector<string> S;

ll solve() {
    UnionFind uf(H + W);
    uf.unite(0, H + 0);
    uf.unite(0, H + W - 1);
    uf.unite(H - 1, H + 0);
    uf.unite(H - 1, H + W - 1);
    REP(i, H) REP(j, W) {
        if (S[i][j] == '#') uf.unite(i, H + j);
    }
    set<int> s[2];
    REP(i, H) s[0].insert(uf.root(i));
    REP(j, W) s[1].insert(uf.root(H + j));

    ll ans = min(s[0].size() - 1, s[1].size() - 1);
    return ans;
}

int main() {
    cin >> H >> W;
    S.resize(H);
    REP(i, H) cin >> S[i];

    cout << solve() << endl;

    return 0;
}
