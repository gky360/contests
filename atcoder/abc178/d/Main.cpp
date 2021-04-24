/*
[abc178] D - Redistribution
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

const int MOD = 1e9 + 7;
const int MAX_N = 2000;

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

int S;
gf fact[MAX_N + 1], finv[MAX_N + 1];

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

gf combi(int n, int k) {
    return (n < 0 || k < 0 || n - k < 0) ? 0
                                         : fact[n] * (finv[k] * finv[n - k]);
}

ll solve() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) fact[i] = fact[i - 1] * i;
    finv[MAX_N] = mod_inv(fact[MAX_N].n, MOD);
    for (int i = MAX_N; i > 0; i--) finv[i - 1] = finv[i] * i;

    gf ans = 0;
    for (int i = 1; i <= S / 3; i++) ans += combi(S - 2 * i - 1, i - 1);

    return ans.n;
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
