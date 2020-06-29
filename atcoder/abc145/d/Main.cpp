/*
[abc145] D - Knight
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e6;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    static gf mod_inv(int a, int m) {
        int u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a;
            u -= t * v;
            swap(a, m);
            swap(u, v);
        }
        return gf(u);
    }
    gf() : n(0) {}
    gf(int n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf operator/(gf x) { return *this * x.inv(); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
    gf& operator/=(gf x) { return *this = (*this / x); }
    gf inv() { return mod_inv(n, MOD); }
};

int X, Y;

ll solve() {
    if (2 * Y - X < 0 || 2 * X - Y < 0 || (2 * Y - X) % 3 != 0) {
        return 0;
    }
    int p = (2 * Y - X) / 3, q = (2 * X - Y) / 3;

    gf fact[MAX_N + 1];
    fact[0] = 1;
    for (int i = 1; i <= (p + q); i++) {
        fact[i] = fact[i - 1] * i;
    }

    gf ans = fact[p + q] / (fact[p] * fact[q]);
    return ans.n;
}

int main() {
    cin >> X >> Y;

    cout << solve() << endl;

    return 0;
}
