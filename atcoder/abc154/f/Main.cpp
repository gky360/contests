/*
[abc154] F - Many Many Paths
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_R = 1e6;
const int MAX_C = 1e6;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    static gf mod_inv(int a, int m) {
        int u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a, u -= t * v;
            swap(a, m), swap(u, v);
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

int R1, C1, R2, C2;
gf fact[MAX_R + MAX_C + 3];

gf calc(int r, int c) {
    return fact[r + c + 2] / (fact[r + 1] * fact[c + 1]) - 1;
}

ll solve() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_R + MAX_C + 2; i++) {
        fact[i] = fact[i - 1] * i;
    }

    gf ans = calc(R2, C2) - calc(R1 - 1, C2) - calc(R2, C1 - 1) +
             calc(R1 - 1, C1 - 1);

    return ans.n;
}

int main() {
    cin >> R1 >> C1 >> R2 >> C2;

    cout << solve() << endl;

    return 0;
}
