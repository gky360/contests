/*
[abc156] E - Roaming
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;
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

gf fact[MAX_N + 1], finv[MAX_N + 1];

gf combi(int n, int k) {
    return (n < 0 || k < 0 || n - k < 0) ? 0
                                         : fact[n] * (finv[k] * finv[n - k]);
}

int N, K;

gf calc(int m) { return combi(N, m) * combi(N - 1, N - m - 1); }

ll solve() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        fact[i] = fact[i - 1] * i;
    }
    finv[MAX_N] = mod_inv(fact[MAX_N].n, MOD);
    for (int i = MAX_N; i > 0; i--) {
        finv[i - 1] = finv[i] * i;
    }

    gf ans = 0;
    for (int i = 0; i <= min(N - 1, K); i++) {
        ans += calc(i);
    }

    return ans.n;
}

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
