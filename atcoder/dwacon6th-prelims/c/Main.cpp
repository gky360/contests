/*
[dwacon6th-prelims] C - Cookie Distribution
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1000;
const int MAX_K = 20;
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

int N, K;
int a[MAX_K + 1];
gf fact[MAX_N + 1], finv[MAX_N + 1];
gf dp[MAX_K + 1][MAX_N + 1];

gf combi(int n, int k) {
    return (k < 0 || n < k) ? 0 : fact[n] * finv[n - k] * finv[k];
}

ll solve() {
    fact[0] = finv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i;
        finv[i] = fact[i].inv();
    }

    dp[0][0] = 1;
    for (int k = 1; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            for (int x = 0; x <= min(n, a[k]); x++) {
                dp[k][n] += dp[k - 1][n - x] * combi(N - x, a[k] - x) * finv[x];
            }
        }
    }
    gf ans = dp[K][N] * fact[N];

    return ans.n;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
