/*
[abc171] F - Strivore
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
const int MAX_N = 1e6;
const int MAX_K = 1e6;

// galois field (full feature)
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

int K;
string S;
gf fact[MAX_N + MAX_K + 1], p25[MAX_N + MAX_K + 1], p26[MAX_N + MAX_K + 1];

gf combi(int n, int k) {
    return (n < 0 || k < 0 || n - k < 0) ? 0
                                         : fact[n] / (fact[k] * fact[n - k]);
}

ll solve() {
    int N = S.length();

    p25[0] = p26[0] = fact[0] = 1;
    for (int i = 1; i <= MAX_N + MAX_K; i++) {
        fact[i] = fact[i - 1] * i;
        p25[i] = p25[i - 1] * 25;
        p26[i] = p26[i - 1] * 26;
    }

    gf ans = 0;
    for (int i = N - 1; i < N + K; i++) {
        ans +=
            combi(i, N - 1) * p25[K - (N + K - i - 1)] * p26[(N + K - i - 1)];
    }

    return ans.n;
}

int main() {
    cin >> K;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
