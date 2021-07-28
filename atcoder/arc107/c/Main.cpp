/*
[arc107] C - Shuffle Permutation
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

const int MAX_N = 50;
const int MOD = 998244353;

int N, K;
int a[MAX_N][MAX_N];

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

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(ll n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
};

gf fact[MAX_N + 1];

bool can(int p, int q) {
    REP(i, N) {
        if (a[i][p] + a[i][q] > K) return false;
    }
    return true;
}

gf calc() {
    UnionFind uf(N);

    REP(q, N) REP(p, q) {
        if (can(p, q)) uf.unite(p, q);
    }

    vector<bool> visited(N);
    gf ret = 1;
    REP(i, N) {
        if (!visited[uf.root(i)]) {
            visited[uf.root(i)] = true;
            ret *= fact[uf.size(i)];
        }
    }
    return ret;
}

ll solve() {
    fact[0] = 1;
    REP(i, N) fact[i + 1] = fact[i] * (i + 1);

    gf ans = 1;
    ans *= calc();
    REP(i, N) REP(j, i) swap(a[i][j], a[j][i]);
    ans *= calc();
    return ans.n;
}

int main() {
    cin >> N >> K;
    REP(i, N) REP(j, N) cin >> a[i][j];

    cout << solve() << endl;

    return 0;
}
