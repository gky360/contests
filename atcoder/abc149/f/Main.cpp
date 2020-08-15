/*
[abc149] F - Surrounded Nodes
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    static gf mod_inv(int a, int m) {
        int u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a;
            u -= t * v;
            swap(a, m);
            swap(u, v);
        }
        return gf(u);
    }
    gf() : n(0) {}
    gf(int n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf operator/(gf x) { return *this * x.inv(); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
    gf& operator/=(gf x) { return *this = (*this / x); }
    gf inv() { return mod_inv(n, MOD); }
};

int N;
vector<int> g[MAX_N];
int s[MAX_N];
gf pow2[MAX_N + 1];

int dfs0(int v, int par = -1) {
    for (int to : g[v]) {
        if (to == par) continue;
        s[v] += dfs0(to, v);
    }
    return s[v] + 1;
}

gf dfs(int v, int par = -1) {
    gf ret = pow2[N - 1] - pow2[N - s[v] - 1];
    for (int to : g[v]) {
        if (to == par) continue;
        ret -= pow2[s[to] + 1] - 1;
        ret += dfs(to, v);
    }
    return ret;
}

ll solve() {
    pow2[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }

    dfs0(0);

    gf ans = dfs(0) / pow2[N];

    return ans.n;
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        g[A - 1].push_back(B - 1);
        g[B - 1].push_back(A - 1);
    }

    cout << solve() << endl;

    return 0;
}
