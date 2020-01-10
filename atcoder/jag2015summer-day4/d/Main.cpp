/*
[jag2015summer-day4] D - Identity Function
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

map<ll, int> prime_factorize(ll n) {
    map<ll, int> ret;
    for (ll d = 2; d * d <= n; d++) {
        if (n % d != 0) {
            continue;
        }
        int e = 0;
        while (n % d == 0) {
            n /= d;
            e++;
        }
        ret[d] = e;
    }
    if (n != 1) {
        ret[n] = 1;
    }
    return ret;
}

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

ll calc_order(ll a, ll m) {
    ll phi_m = euler_phi(m);
    ll ret = phi_m;
    auto pf = prime_factorize(phi_m);
    for (auto &pe : pf) {
        ll p = pe.first;
        while (ret % p == 0 && pow_mod(a, ret / p, m) == 1) {
            ret /= p;
        }
    }
    return ret;
}

int N;

ll solve() {
    auto pf = prime_factorize(N);

    ll l = 1;
    for (auto &pe : pf) {
        if (pe.second > 1) {
            return -1;
        }
        l = lcm(l, pe.first - 1);
    }
    if (gcd(N, l) != 1) {
        return -1;
    }
    if (l == 1) {
        return 1;
    }

    return calc_order(N, l);
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
