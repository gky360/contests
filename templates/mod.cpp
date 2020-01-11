#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll d = gcd(a, b);
    return a * b / d;
}

/**
 * 素因数分解
 * @return n = p0^e0 * p1^e1 * ... のとき、 [{p0, e0}, {p1, e1}, ...]
 */
vector<pli> prime_factorize(ll n) {
    vector<pli> ret;
    for (ll d = 2; d * d <= n; d++) {
        if (n % d != 0) {
            continue;
        }
        int e = 0;
        while (n % d == 0) {
            n /= d;
            e++;
        }
        ret.push_back({d, e});
    }
    if (n != 1) {
        ret.push_back({n, 1});
    }
    return ret;
}

/**
 * a^n mod m
 */
ll pow_mod(ll a, ll n, ll m) {
    ll ret = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            (ret *= a) %= m;
        }
        (a *= a) %= m;
    }
    return ret;
}

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

// ll mod_inv(ll a, ll m) {
//     ll x, y;
//     extgcd(a, m, x, y);
//     return (m + x) % m;
// }

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

/**
 * オイラー関数
 *
 * n 以下の n と互いに素な自然数の個数。
 * x と n が互いに素のとき、 x^euler_phi(m) mod m = 1 が成り立つ。
 */
ll euler_phi(ll n) {
    ll ret = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ret = ret / i * (i - 1);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) {
        ret = ret / n * (n - 1);
    }
    return ret;
}

/*
 * a の位数を計算する
 *
 * a の位数 ... a^k mod m = 1 となる最小の k
 */
ll calc_order(ll a, ll m) {
    ll phi_m = euler_phi(m);
    ll ret = phi_m;
    auto pf = prime_factorize(phi_m);
    for (auto& pe : pf) {
        ll p = pe.first;
        while (ret % p == 0 && pow_mod(a, ret / p, m) == 1) {
            ret /= p;
        }
    }
    return ret;
}

int main() { return 0; }
