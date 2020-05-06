/*
[jsc2019-qual] E - Card Collector
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MAX_H = 1e5;
const int MAX_W = 1e5;

const int MAX_V = MAX_H + MAX_W;

class UnionFind {
public:
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) {
            return false;
        }
        if (data[y] < data[x]) {
            swap(x, y);
        }
        data[x] += data[y];
        data[y] = x;

        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : (data[x] = root(data[x])); }
    int size(int x) { return -data[root(x)]; }
};

int N, H, W;
pair<int, pii> ARC[MAX_N];
int ce[MAX_V];

ll solve() {
    UnionFind uf(H + W);

    sort(ARC, ARC + N);

    ll ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        int u = ARC[i].second.first, v = H + ARC[i].second.second;
        int ne = uf.same(u, v) ? ce[uf.root(u)] + 1
                               : ce[uf.root(u)] + ce[uf.root(v)] + 1;
        int nv = uf.same(u, v) ? uf.size(u) : uf.size(u) + uf.size(v);
        if (ne <= nv) {
            uf.unite(u, v);
            ce[uf.root(u)] = ne;
            ans += ARC[i].first;
        }
    }

    return ans;
}

int main() {
    cin >> N >> H >> W;
    for (int i = 0; i < N; i++) {
        int r, c, a;
        cin >> r >> c >> a;
        r--, c--;
        ARC[i] = {a, {r, c}};
    }

    cout << solve() << endl;

    return 0;
}
