// ARC093
// E - Bichrome Spanning Tree

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

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

struct edge {
    int u, v;
    ll w;
    bool operator<(const edge &e) { return w < e.w; }
};

constexpr ll MOD = 1e9 + 7;

int N, M;
ll X;
vector<edge> es;

int solve() {
    sort(es.begin(), es.end());

    vector<int> pow2(M + 1);
    pow2[0] = 1;
    for (int i = 0; i < M; i++) {
        pow2[i + 1] = pow2[i] * 2 % MOD;
    }

    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < M; i++) {
        UnionFind uf = UnionFind(N);
        ll sum = es[i].w;
        uf.unite(es[i].u, es[i].v);
        for (int j = 0; j < M; j++) {
            if (!uf.same(es[j].u, es[j].v)) {
                uf.unite(es[j].u, es[j].v);
                sum += es[j].w;
            }
        }
        if (sum < X) {
            cnt_a++;
        } else if (sum == X) {
            cnt_b++;
        }
    }

    if (cnt_b == 0) {
        return 0;
    }
    if (cnt_a == 0) {
        return ((pow2[cnt_b] + MOD - 2) % MOD) * pow2[M - cnt_b] % MOD;
    }
    return ((pow2[cnt_b] + MOD - 1) % MOD) * pow2[M - cnt_a - cnt_b] % MOD * 2 %
           MOD;
}

int main() {
    cin >> N >> M;
    cin >> X;
    es.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> es[i].u >> es[i].v >> es[i].w;
        es[i].u--;
        es[i].v--;
    }

    cout << solve() << endl;

    return 0;
}
