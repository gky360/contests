#include <algorithm>
using namespace std;
typedef long long int ll;

ll extgcd(ll a, ll b, ll& x, ll& y) {
    ll d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

ll mod_inv(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x) % m;
}

const int MAX_N = 1e5;
const int MOD = 1e9 + 7;

// galois field
class gf {
public:
    int n;
    static int extgcd(int a, int b, int& x, int& y) {
        int d = a;
        if (b != 0) {
            d = extgcd(b, a % b, y, x);
            y -= (a / b) * x;
        } else {
            x = 1;
            y = 0;
        }
        return d;
    }
    static int mod_inv(int a, int m) {
        int x, y;
        extgcd(a, m, x, y);
        return (m + x) % m;
    }
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(const gf x) const { return gf((n + x.n) % MOD); }
    gf operator-(const gf x) const { return gf((n - x.n + MOD) % MOD); }
    gf operator*(const gf x) const { return gf((1LL * n * x.n) % MOD); }
    gf operator/(const gf x) const { return *this * x.inv(); }
    gf& operator+=(const gf x) { return *this = (*this + x); }
    gf& operator-=(const gf x) { return *this = (*this - x); }
    gf& operator*=(const gf x) { return *this = (*this * x); }
    gf& operator/=(const gf x) { return *this = (*this / x); }
    gf inv() const { return gf(mod_inv(n, MOD)); }
    gf pow(ll e) const {
        gf a = *this;
        gf x = 1;
        for (; e > 0; e >>= 1) {
            if (e & 1) {
                x = x * a;
            }
            a = a * a;
        }
        return x;
    }
};

ll fact[MAX_N + 1], finv[MAX_N + 1], inv[MAX_N + 1];

gf combi(int n, int k) {
    return (n < 0 || k < 0 || n - k < 0) ? 0
                                         : fact[n] / (fact[k] * fact[n - k]);
}

int main() {
    // calc fact, finv
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    finv[MAX_N] = mod_inv(fact[MAX_N], MOD);
    for (int i = MAX_N - 1; i > 0; i--) {
        finv[i] = finv[i + 1] * i % MOD;
    }

    // calc fact, inv,  finv
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = (finv[i - 1] * inv[i]) % MOD;
    }

    return 0;
}
