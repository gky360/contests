/*
[abc180] F - Unbranched
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 300;
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

int N, M, L;
gf fact[MAX_N + 1], finv[MAX_N + 1];

gf combi(int n, int k) {
    return (k < 0 || n < k) ? 0 : (fact[n] * finv[n - k] * finv[k]);
}

gf calc(int l) {
    gf dp[MAX_N + 1][MAX_N + 1];
    dp[0][0] = 1;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m <= M; m++) {
            dp[n + 1][m] += dp[n][m];
            for (int k = 2; k <= min(min(N - n, M - m + 1), l); k++) {
                dp[n + k][m + k - 1] +=
                    dp[n][m] * combi(N - n - 1, k - 1) * fact[k] / 2;
                if (m + k <= M) {
                    dp[n + k][m + k] += dp[n][m] * combi(N - n - 1, k - 1) *
                                        (k == 2 ? 1 : fact[k - 1] / 2);
                }
            }
        }
    }
    return dp[N][M];
}

ll solve() {
    fact[0] = finv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i;
        finv[i] = fact[i].inv();
    }

    gf ans = calc(L) - calc(L - 1);
    return ans.n;
}

int main() {
    cin >> N >> M >> L;

    cout << solve() << endl;

    return 0;
}
