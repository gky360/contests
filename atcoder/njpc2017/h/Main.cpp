/*
[njpc2017] H - 白黒ツリー
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const pii INF = pii(1e9, MAX_N);

template <typename T>
class BIT {
public:
    vector<T> b;
    BIT(int n) : b(n + 1) {}
    T sum(int i) {  // i : [0, n], returns sum of [0, i)
        T s = 0;
        for (; i > 0; i -= i & -i) {
            s += b[i];
        }
        return s;
    }
    void add(int i, T x) {  // i : [0, n)
        for (i += 1; i < (int)b.size(); i += i & -i) {
            b[i] += x;
        }
        return;
    }
};

template <typename T>
class RMQ {
public:
    int n;
    vector<T> data;
    RMQ(int _n) {
        n = 1;
        while (n < _n) {
            n <<= 1;
        }
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
        if (r <= a || b <= l) {
            return INF;
        }
        if (a <= l && r <= b) {
            return data[k];
        }
        return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
                   query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

int N;
int p[MAX_N];
int C[MAX_N];
int Q;
vector<int> g[MAX_N];
int id[MAX_N];
int es[MAX_N * 2];
BIT<int> bit(MAX_N * 2);
RMQ<pii> rmq(MAX_N * 2);

void dfs(int v, int par, int d, int &k) {
    id[v] = k;
    for (int to : g[v]) {
        if (to == par) continue;
        rmq.update(k, pii(d, v));
        es[to * 2 + 0] = k++;
        dfs(to, v, d + 1, k);
        rmq.update(k, pii(d + 1, to));
        es[to * 2 + 1] = k++;
    }
}

void init() {
    int k = 0;
    dfs(0, -1, 0, k);
    for (int i = 1; i < N; i++) {
        if (C[i] == C[p[i]]) {
            bit.add(es[i * 2 + 0], 1);
            bit.add(es[i * 2 + 1], -1);
        }
    }
}

void update(int u) {
    if (u == 0) return;

    if (bit.sum(es[u * 2 + 0] + 1) - bit.sum(es[u * 2 + 0])) {
        bit.add(es[u * 2 + 0], -1);
        bit.add(es[u * 2 + 1], 1);
    } else {
        bit.add(es[u * 2 + 0], 1);
        bit.add(es[u * 2 + 1], -1);
    }
}

bool solve(int u, int v) {
    int iu = id[u], iv = id[v];
    if (iu > iv) swap(iu, iv);
    int lca = rmq.query(iu, iv + 1).second;
    int w = bit.sum(id[u]) + bit.sum(id[v]) - 2 * bit.sum(id[lca]);
    return w == 0;
}

int main() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> p[i];
        p[i]--;
        g[i].push_back(p[i]);
        g[p[i]].push_back(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
    }
    init();

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int u;
            cin >> u;
            update(u - 1);
        } else {
            int u, v;
            cin >> u >> v;
            cout << (solve(u - 1, v - 1) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
