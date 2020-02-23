/*
[tenka1-2013-final] D - 天下一ボディービルコンテスト
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 30;
const int MAX_A = 30;
const int MAX_K = MAX_N * MAX_A;
const int MOD = 1000000007;

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

int N, D;
int a[MAX_N];
gf dp[MAX_N + 1][MAX_N + 1][MAX_K + MAX_N + 1];
gf fact[MAX_K + MAX_N + 1], finv[MAX_K + MAX_N + 1], dc[MAX_K + 1];

ll mod_inv(ll a, ll m) {
    ll u = 0, v = 1, mod = m;
    while (a != 0) {
        ll t = m / a;
        m -= t * a;
        u -= t * v;
        swap(a, m);
        swap(u, v);
    }
    return (u + mod) % mod;
}

ll pow_mod(ll a, ll n, ll m) {
    ll ret = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            (ret *= a) %= m;
        }
        (a *= a) %= m;
    }
    return ret;
}

gf combi(int n, int k) {
    return (n < 0 || k < 0 || n - k < 0) ? 0
                                         : fact[n] * (finv[k] * finv[n - k]);
}

ll solve() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_K + MAX_N; i++) {
        fact[i] = fact[i - 1] * i;
    }
    finv[MAX_K + MAX_N] = fact[MAX_K + MAX_N].inv();
    for (int i = MAX_K + MAX_N; i > 0; i--) {
        finv[i - 1] = finv[i] * i;
    }

    dc[0] = 1;
    for (int i = 0; i < MAX_K; i++) {
        dc[i + 1] = dc[i] * (D - i) / (i + 1);
    }

    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k <= MAX_K; k++) {
                dp[i + 1][j][k] += dp[i][j][k];
                for (int l = 0; l < a[i]; l++) {
                    dp[i + 1][j + 1][k + l] += dp[i][j][k] * combi(k + l, l);
                }
            }
        }
    }

    gf ans = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= min(MAX_K, D); j++) {
            ans += dp[N][i][j] * dc[j] * pow_mod(N - i, D - j, MOD) *
                   (i % 2 ? -1 : 1);
        }
    }

    return ans.n;
}

int main() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
