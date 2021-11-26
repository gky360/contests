/*
[keyence2021] C - Robot on Grid
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

const int MAX_H = 5000, MAX_W = 5000, MAX_K = 2e5;
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

gf mod_pow(gf a, ll n) {
    gf ret = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) ret *= a;
        a *= a;
    }
    return ret;
}

int H, W, K;
int h[MAX_K], w[MAX_K];
char c[MAX_K];

ll solve() {
    vector<vector<char>> x(H, vector<char>(W, ' '));
    vector<vector<gf>> dp(H, vector<gf>(W));
    REP(k, K) x[h[k]][w[k]] = c[k];

    gf p = 665496236;  // 2/3
    dp[0][0] = 1;
    REP(i, H) REP(j, W) {
        if (i + 1 < H && (x[i][j] == ' ' || x[i][j] == 'X' || x[i][j] == 'D'))
            dp[i + 1][j] += dp[i][j] * (x[i][j] == ' ' ? p : 1);
        if (j + 1 < W && (x[i][j] == ' ' || x[i][j] == 'X' || x[i][j] == 'R'))
            dp[i][j + 1] += dp[i][j] * (x[i][j] == ' ' ? p : 1);
    }

    gf ans = dp[H - 1][W - 1] * mod_pow(3, H * W - K);
    return ans.n;
}

int main() {
    cin >> H >> W >> K;
    REP(k, K) cin >> h[k] >> w[k] >> c[k], h[k]--, w[k]--;

    cout << solve() << endl;

    return 0;
}
