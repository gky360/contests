/*
[arc106] D - Powers
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

const int MOD = 998244353;
const int MAX_N = 2e5;
const int MAX_K = 300;

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

int N, K;
int A[MAX_N];
gf fact[MAX_K + 1];
gf z[MAX_K + 1], w[MAX_K + 1];

void solve() {
    gf a[MAX_N], a2[MAX_N];
    REP(i, N) a[i] = 1, a2[i] = 1;
    fact[0] = 1;
    z[0] = N;
    for (int k = 1; k <= K; k++) {
        fact[k] = fact[k - 1] * k;
        REP(i, N) {
            z[k] += (a[i] *= A[i]);
            w[k] += (a2[i] *= 2 * A[i]);
        }
        z[k] /= fact[k];
    }

    for (int x = 1; x <= K; x++) {
        gf s = 0;
        REP(k, x + 1) s += z[k] * z[x - k];
        s *= fact[x];
        gf ans = (s - w[x]) / 2;
        cout << ans.n << endl;
    }
}

int main() {
    cin >> N >> K;
    REP(i, N) cin >> A[i];

    solve();

    return 0;
}
