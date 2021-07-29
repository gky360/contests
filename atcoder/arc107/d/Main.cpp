/*
[arc107] D - Number of Multisets
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

const int MAX_N = 3000;
const int MOD = 998244353;

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

int N, K;
gf dp[MAX_N + 1][MAX_N + 1];

ll solve() {
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int k = i; k > 0; k--) {
            dp[i][k] = dp[i - 1][k - 1];
            if (i >= 2 * k) dp[i][k] += dp[i][2 * k];
        }
    }

    ll ans = dp[N][K].n;
    return ans;
}

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
