/*
[abc162] E - Sum of gcd of Tuples (Hard)
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

const int MAX_K = 1e5;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
};

int N, K;
gf pn[MAX_K + 1];
gf dp[MAX_K + 1];

ll solve() {
    for (int k = 1; k <= K; k++) {
        pn[k] = 1;
        gf p = k;
        for (int n = N; n > 0; n >>= 1) {
            if (n & 1) pn[k] *= p;
            p *= p;
        }
    }

    gf ans = 0;
    for (int x = K; x > 0; x--) {
        dp[x] = pn[K / x];
        for (int i = x * 2; i <= K; i += x) {
            dp[x] -= dp[i];
        }
        ans += dp[x] * x;
    }

    return ans.n;
}

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
