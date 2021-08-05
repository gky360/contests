/*
[abc181] F - Silver Woods
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

const int MAX_N = 100;

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
double x[MAX_N], y[MAX_N];

double solve() {
    vector<pair<double, pii>> es;
    REP(i, N) REP(j, N) {
        double dx = x[i] - x[j], dy = y[i] - y[j];
        es.push_back({sqrt(dx * dx + dy * dy), {i, j}});
    }
    REP(i, N) {
        es.push_back({y[i] + 100, {i, N}});
        es.push_back({100 - y[i], {i, N + 1}});
    }
    es.push_back({200, {N, N + 1}});

    sort(ALL(es));

    UnionFind uf(N + 2);
    for (auto [d, pq] : es) {
        auto [p, q] = pq;
        uf.unite(p, q);
        if (uf.same(N, N + 1)) {
            return d * 0.5;
        }
    }

    return -1;
}

int main() {
    cin >> N;
    REP(i, N) cin >> x[i] >> y[i];

    cout << fixed << setprecision(18) << solve() << endl;

    return 0;
}
