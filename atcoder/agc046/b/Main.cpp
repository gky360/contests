/*
[agc046] B - Extension
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

const int MAX_X = 3000;
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

int A, B, C, D;
gf dp[MAX_X + 1][MAX_X + 1];

ll solve() {
    dp[A][B] = 1;

    for (int i = A; i <= C; i++) {
        for (int j = B; j <= D; j++) {
            if (A < i) dp[i][j] += dp[i - 1][j] * j;
            if (B < j) dp[i][j] += dp[i][j - 1] * i;
            if (A < i && B < j)
                dp[i][j] -= dp[i - 1][j - 1] * (i - 1) * (j - 1);
        }
    }

    ll ans = dp[C][D].n;
    return ans;
}

int main() {
    cin >> A >> B >> C >> D;

    cout << solve() << endl;

    return 0;
}
