/*
[keyence2019] E - Connecting Cities
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

typedef pair<ll, pii> edge;

const int MAX_N = 2e5;
const pli INF = {1e18, -1};

template <typename T>
class RMQ {
public:
    int n;
    vector<T> dat;
    void init(int _n) {
        n = 1;
        while (n < _n) {
            n <<= 1;
        }
        dat.reserve(2 * n - 1);
        fill(dat.begin(), dat.end(), INF);
    }
    void update(int k, T a) {
        k += n - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    T query(int a, int b) { return query(a, b, 0, 0, n); }

private:
    T query(int a, int b, int k, int l, int r) {  // [a, b), [l, r)
        if (r <= a || b <= l) {
            return INF;
        }
        if (a <= l && r <= b) {
            return dat[k];
        }
        return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
                   query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

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

int N;
ll D;
ll A[MAX_N];
RMQ<pli> tl, tr;

ll solve() {
    vector<pli> ais;
    tl.init(N);
    tr.init(N);
    for (int i = 0; i < N; i++) {
        ais.push_back({A[i], i});
        tl.update(i, {A[i] - i * D, i});
        tr.update(i, {A[i] + i * D, i});
    }
    sort(ais.begin(), ais.end(), greater<pli>());

    vector<edge> q;
    for (auto& ai : ais) {
        int i = ai.second;
        pli ci;
        if ((ci = tl.query(0, i)) != INF) {
            edge e = {ci.first + A[i] + i * D, {ci.second, i}};
            q.push_back(e);
        }
        if ((ci = tr.query(i + 1, N)) != INF) {
            edge e = {ci.first + A[i] - i * D, {ci.second, i}};
            q.push_back(e);
        }
        tl.update(i, INF);
        tr.update(i, INF);
    }
    sort(q.begin(), q.end());

    ll ans = 0;
    UnionFind uf(N);
    for (auto& e : q) {
        int u = e.second.first, v = e.second.second;
        if (!uf.same(u, v)) {
            ans += e.first;
            uf.unite(u, v);
        }
    }

    return ans;
}

int main() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
