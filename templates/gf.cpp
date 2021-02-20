#include <algorithm>
using namespace std;
typedef long long int ll;

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

const int MAX_N = 1e5;
const int MOD = 1e9 + 7;

// galois field
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

// // galois field (full feature)
// class gf {
// public:
//     int n;
//     static gf mod_inv(int a, int m) {
//         int u = 0, v = 1;
//         while (a != 0) {
//             int t = m / a;
//             m -= t * a, u -= t * v;
//             swap(a, m), swap(u, v);
//         }
//         return gf(u);
//     }
//     gf() : n(0) {}
//     gf(ll n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
//     gf operator+(gf x) { return gf((n + x.n) % MOD); }
//     gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
//     gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
//     gf operator/(gf x) { return *this * x.inv(); }
//     gf& operator+=(gf x) { return *this = (*this + x); }
//     gf& operator-=(gf x) { return *this = (*this - x); }
//     gf& operator*=(gf x) { return *this = (*this * x); }
//     gf& operator/=(gf x) { return *this = (*this / x); }
//     gf inv() { return mod_inv(n, MOD); }
// };

gf fact[MAX_N + 1], finv[MAX_N + 1], inv[MAX_N + 1];

gf combi(int n, int k) {
    return (n < 0 || k < 0 || n - k < 0) ? 0
                                         : fact[n] * (finv[k] * finv[n - k]);
    // return (n < 0 || k < 0 || n - k < 0) ? 0
    //                                      : fact[n] / (fact[k] * fact[n - k]);
}

gf perm(int n, int k) {
    return fact[n] * finv[n - k];
    // return fact[n] / fact[n - k];
}

gf mod_pow(gf a, ll n) {
    gf ret = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) ret *= a;
        a *= a;
    }
    return ret;
}

int main() {
    // calc fact, finv
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        fact[i] = fact[i - 1] * i;
    }
    finv[MAX_N] = mod_inv(fact[MAX_N].n, MOD);
    // finv[MAX_N] = fact[MAX_N].inv();
    for (int i = MAX_N; i > 0; i--) {
        finv[i - 1] = finv[i] * i;
    }

    // calc fact, inv, finv
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        fact[i] = fact[i - 1] * i;
        inv[i] = gf(0) - inv[MOD % i] * (MOD / i);
        finv[i] = finv[i - 1] * inv[i];
    }

    return 0;
}
