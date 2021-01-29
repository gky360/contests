/*
[abc169] F - Knapsack for All Subsets
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
const int MAX_S = 3000;
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

int N, S;
int A[MAX_N];
gf dp[MAX_N + 1][MAX_S + 1];

ll solve() {
    dp[0][0] = 1;
    REP(i, N) REP(j, S + 1) {
        if (j - A[i] >= 0) dp[i + 1][j] += dp[i][j - A[i]];
        dp[i + 1][j] += dp[i][j] * 2;
    }

    ll ans = dp[N][S].n;
    return ans;
}

int main() {
    cin >> N >> S;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
