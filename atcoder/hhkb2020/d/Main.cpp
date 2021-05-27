/*
[hhkb2020] D - Squares
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

int T;

ll solve(gf n, gf a, gf b) {
    gf l = (n.n - a.n - b.n) < 0
               ? 0
               : (n - a - b + 2) * (n - a - b + 1) * ((MOD + 1) / 2);
    gf x = (n - a + 1) * (n - b + 1) - l * 2;
    gf ans = (n - a + 1) * (n - a + 1) * (n - b + 1) * (n - b + 1) - x * x;
    return ans.n;
}

int main() {
    cin >> T;
    REP(i, T) {
        int N, A, B;
        cin >> N >> A >> B;
        cout << solve(N, A, B) << endl;
    }

    return 0;
}
