/*
[arc108] D - AB
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

int N;
char c[2][2];

gf mod_pow(gf a, ll n) {
    gf ret = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) ret *= a;
        a *= a;
    }
    return ret;
}

ll solve() {
    if (c[0][1] == 'B') {
        if (c[1][1] == 'B') return 1;
        if (c[1][0] == 'A') return mod_pow(2, N - 3).n;
        gf p0 = 1, p1 = 1;
        for (int i = 0; i < N - 3; i++) swap(p0, p1), p0 += p1;
        return p0.n;
    }
    if (c[0][0] == 'A') return 1;
    if (c[1][0] == 'B') return mod_pow(2, N - 3).n;
    gf p0 = 1, p1 = 1;
    for (int i = 0; i < N - 3; i++) swap(p0, p1), p0 += p1;
    return p0.n;
}

int main() {
    cin >> N;
    REP(i, 2) REP(j, 2) cin >> c[i][j];

    cout << solve() << endl;

    return 0;
}
