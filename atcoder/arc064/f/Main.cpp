/*
[arc064] F - Rotated Palindromes
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_D = 1400;
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
gf dp[MAX_D];

vector<int> divisors(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

ll mod_pow(ll a, ll n, ll m) {
    ll ret = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            (ret *= a) %= m;
        }
        (a *= a) %= m;
    }
    return ret;
}

ll solve() {
    auto divs = divisors(N);
    int D = divs.size();
    sort(divs.begin(), divs.end());

    for (int i = 0; i < D; i++) {
        dp[i] = mod_pow(K, (divs[i] + 1) / 2, MOD);
        for (int j = 0; j < i; j++) {
            if (divs[i] % divs[j] == 0) {
                dp[i] -= dp[j];
            }
        }
    }

    gf ans = 0;
    for (int i = 0; i < D; i++) {
        if (divs[i] % 2) {
            ans += dp[i] * divs[i];
        } else {
            ans += dp[i] * (divs[i] / 2);
        }
    }

    return ans.n;
}

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
