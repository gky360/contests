/*
[m-solutions2019] E - Product of Arithmetic Progression
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MOD = 1000003;

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
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf operator/(gf x) { return *this * x.inv(); }
    gf inv() { return gf(mod_inv(n, MOD)); }
    gf pow(int n) {
        gf a = *this;
        gf x = 1;
        for (; n > 0; n >>= 1) {
            if (n & 1) {
                x = x * a;
            }
            a = a * a;
        }
        return x;
    }
};

int Q;
gf fact[MOD];

void prepare() {
    fact[0] = 1;
    for (int i = 1; i < MOD; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

ll solve(gf x, gf d, int n) {
    if (d.n == 0) {
        return x.pow(n).n;
    }
    gf xdd = x / d;
    if (xdd.n + n - 1 >= MOD) {
        return 0;
    }
    gf ans = fact[xdd.n + n - 1] / fact[xdd.n - 1] * d.pow(n);
    return ans.n;
}

int main() {
    cin >> Q;

    prepare();
    for (int i = 0; i < Q; i++) {
        int x, d, n;
        cin >> x >> d >> n;
        cout << solve(x, d, n) << endl;
    }

    return 0;
}
