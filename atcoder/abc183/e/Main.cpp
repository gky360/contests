/*
[abc183] E - Queen on Grid
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

const int MAX_H = 2000;
const int MAX_W = 2000;
const int MOD = 1e9 + 7;

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

int H, W;
string S[MAX_H];
gf x[MAX_H][MAX_W], y[MAX_H][MAX_W], z[MAX_H][MAX_W];
gf dp[MAX_H][MAX_W];

ll solve() {
    dp[0][0] = 1;
    REP(i, H) REP(j, W) {
        if ((i == 0 && j == 0) || S[i][j] == '#') continue;
        if (j > 0) x[i][j] = x[i][j - 1] + dp[i][j - 1];
        if (i > 0) y[i][j] = y[i - 1][j] + dp[i - 1][j];
        if (i > 0 && j > 0) z[i][j] = z[i - 1][j - 1] + dp[i - 1][j - 1];
        dp[i][j] = x[i][j] + y[i][j] + z[i][j];
    }

    ll ans = dp[H - 1][W - 1].n;
    return ans;
}

int main() {
    cin >> H >> W;
    REP(i, H) cin >> S[i];

    cout << solve() << endl;

    return 0;
}
