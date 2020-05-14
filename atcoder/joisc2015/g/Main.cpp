/*
[joisc2015] G - 道路整備
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100000;
const int MAX_Q = 300000;
const pii INF = pii(1e9, MAX_N);

int dep[MAX_N];

class UnionFind {
public:
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (dep[y] < dep[x]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : (data[x] = root(data[x])); }
    int size(int x) { return -data[root(x)]; }
};

template <typename T>
class BIT {
public:
    vector<T> b;
    BIT(int n) : b(n + 1) {}
    T sum(int i) {  // i : [0, n], returns sum of [0, i)
        T s = 0;
        for (; i > 0; i -= i & -i) s += b[i];
        return s;
    }
    void add(int i, T x) {  // i : [0, n)
        for (i += 1; i < (int)b.size(); i += i & -i) b[i] += x;
    }
};

template <typename T>
class LinearBIT {
public:
    BIT<T> bit0, bit1;
    LinearBIT(int n) : bit0(n), bit1(n) {}
    T sum(int i) { return bit1.sum(i) * i + bit0.sum(i); }
    void add(int l, int r, T x) {  // [l, r)
        bit0.add(l, -x * l);
        bit1.add(l, x);
        bit0.add(r, x * r);
        bit1.add(r, -x);
    }
};

template <typename T>
class RMQ {
public:
    int n;
    vector<T> data;
    RMQ(int _n) {
        n = 1;
        while (n < _n) n <<= 1;
        data.resize(2 * n - 1);
        fill(data.begin(), data.end(), INF);
    }
    void update(int k, T a) {
        k += n - 1;
        data[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = min(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }
    T query(int a, int b) { return query(a, b, 0, 0, n); }

private:
    T query(int a, int b, int k, int l, int r) {  // [a, b), [l, r)
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return data[k];
        return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
                   query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

int N, Q;
int T[MAX_Q], A[MAX_Q], B[MAX_Q];
vector<int> g[MAX_N];
bool visited[MAX_N];
int ls[MAX_N], rs[MAX_N], id[MAX_N];
int par[MAX_N];
LinearBIT<int> bit(MAX_N);
RMQ<pii> rmq(MAX_N * 2);

void dfs(int v, int p, int d, int &idx, int &idx2) {
    if (visited[v]) return;
    visited[v] = true;
    par[v] = p;
    dep[v] = d;

    ls[v] = idx++;
    bit.add(ls[v], ls[v] + 1, d);
    rmq.update(idx2, pii(d, v));
    id[v] = idx2++;
    for (int to : g[v]) {
        if (visited[to]) continue;
        dfs(to, v, d + 1, idx, idx2);
        rmq.update(idx2++, pii(d, v));
    }
    rs[v] = idx;
}

int dis(int v) { return bit.sum(ls[v] + 1) - bit.sum(ls[v]); }

void init() {
    UnionFind uf(N);
    for (int i = 0; i < Q; i++) {
        if (T[i] == 1 && !uf.same(A[i], B[i])) {
            uf.unite(A[i], B[i]);
            g[A[i]].push_back(B[i]);
            g[B[i]].push_back(A[i]);
        }
    }

    int idx = 0, idx2 = 0;
    for (int i = 0; i < N; i++) {
        dfs(i, -1, 0, idx, idx2);
    }
}

void solve() {
    init();

    UnionFind uf1(N), uf2(N);
    for (int i = 0; i < Q; i++) {
        if (T[i] == 1) {
            if (uf1.same(A[i], B[i])) {
                int p = id[A[i]], q = id[B[i]];
                if (p > q) swap(p, q);
                int lca = rmq.query(p, q + 1).second;
                for (int init_v : {A[i], B[i]}) {
                    for (int v = uf2.root(init_v); dep[v] > dep[lca];
                         v = uf2.root(v)) {
                        bit.add(ls[v], rs[v], -1);
                        uf2.unite(v, par[v]);
                    }
                }
            } else {
                uf1.unite(A[i], B[i]);
            }
        } else {
            int ans;
            if (uf1.same(A[i], B[i])) {
                int p = id[A[i]], q = id[B[i]];
                if (p > q) swap(p, q);
                int lca = rmq.query(p, q + 1).second;
                ans = dis(A[i]) + dis(B[i]) - dis(lca) * 2;
            } else {
                ans = -1;
            }
            cout << ans << endl;
        }
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> T[i] >> A[i] >> B[i];
        A[i]--, B[i]--;
    }

    solve();

    return 0;
}
