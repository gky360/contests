/*
[acl1] A - Reachable Towns
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

const int MAX_N = 200000;

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

int N;
int x[MAX_N], y[MAX_N];
int ans[MAX_N];

void solve() {
    UnionFind uf(N);
    vector<pair<pii, int>> xyi;
    REP(i, N) xyi.push_back({{x[i], y[i]}, i});
    sort(ALL(xyi));

    vector<int> s;
    REP(j, N) {
        int i = xyi[j].second;
        int p = i;
        while (!s.empty() && y[s.back()] < y[i]) {
            int ii = s.back();
            s.pop_back();
            uf.unite(i, ii);
            if (p == i) p = ii;
        }
        s.push_back(p);
    }

    REP(i, N) cout << uf.size(i) << endl;
}

int main() {
    cin >> N;
    REP(i, N) cin >> x[i] >> y[i], x[i]--, y[i]--;

    solve();

    return 0;
}
