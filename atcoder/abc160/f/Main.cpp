/*
[abc160] F - Distributing Integers
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

const int MAX_N = 2e5;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    static gf mod_inv(int a, int m) {
        int u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a, u -= t * v;
            swap(a, m), swap(u, v);
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

gf fact[MAX_N + 1], finv[MAX_N + 1];
int N;
vector<int> g[MAX_N];
int cnt[MAX_N];
gf dp[MAX_N];
gf ans[MAX_N];

void dfs1(int v, int par = -1) {
    dp[v] = 1;
    for (int to : g[v]) {
        if (to == par) continue;
        dfs1(to, v);
        cnt[v] += cnt[to];
        dp[v] *= finv[cnt[to]] * dp[to];
    }
    dp[v] *= fact[cnt[v]];
    cnt[v]++;
}

void dfs2(int v, int par = -1) {
    ans[v] = 1;
    for (int to : g[v]) {
        ans[v] *= finv[cnt[to]] * dp[to];
    }
    ans[v] *= fact[N - 1];

    for (int to : g[v]) {
        if (to == par) continue;
        cnt[v] = N - cnt[to];
        dp[v] = ans[v] * finv[N - 1] * fact[cnt[to]] / dp[to] *
                fact[N - cnt[to] - 1];
        dfs2(to, v);
    }
}

void solve() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        fact[i] = fact[i - 1] * i;
    }
    finv[MAX_N] = gf(1) / fact[MAX_N];
    for (int i = MAX_N; i > 0; i--) {
        finv[i - 1] = finv[i] * i;
    }

    dfs1(0);
    dfs2(0);

    for (int i = 0; i < N; i++) {
        cout << ans[i].n << endl;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    solve();

    return 0;
}
