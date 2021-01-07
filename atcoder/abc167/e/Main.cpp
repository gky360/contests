/*
[abc167] E - Colorful Blocks
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

const int MAX_N = 2e5;
const int MOD = 998244353;

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
    gf(ll n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
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

int N, M, K;

gf fact[MAX_N + 1];
gf pm[MAX_N];

gf combi(int n, int k) {
    return (n < 0 || k < 0 || n - k < 0) ? 0
                                         : fact[n] / (fact[k] * fact[n - k]);
}

ll solve() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        fact[i] = fact[i - 1] * i;
    }

    pm[0] = 1;
    REP(i, N - 1) pm[i + 1] = pm[i] * (M - 1);

    gf ans = 0;
    REP(k, K + 1) ans += combi(N - 1, k) * pm[N - k - 1] * M;

    return ans.n;
}

int main() {
    cin >> N >> M >> K;

    cout << solve() << endl;

    return 0;
}
