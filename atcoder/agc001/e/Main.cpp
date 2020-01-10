/*
[agc001] E - BBQ Hard
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 200000;
const int MAX_A = 2000;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    static int mod_inv(int a, int m) {
        int u = 0, v = 1;
        while (a != 0) {
            int t = m / a;
            m -= t * a;
            u -= t * v;
            swap(a, m);
            swap(u, v);
        }
        return (u + MOD) % MOD;
    }
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf operator/(gf x) { return *this * x.inv(); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
    gf& operator/=(gf x) { return *this = (*this / x); }
    gf inv() { return gf(mod_inv(n, MOD)); }
};

gf fact[4 * MAX_A + 1];

gf combi(int n, int k) {
    return (n < 0 || k < 0 || n - k < 0) ? 0
                                         : fact[n] / (fact[k] * fact[n - k]);
}

int N;
int A[MAX_N], B[MAX_N];
gf m_raw[2 * (MAX_A + 1)][2 * (MAX_A + 1)];

gf& m(int x, int y) { return m_raw[x + MAX_A][y + MAX_A]; }

ll solve() {
    fact[0] = 1;
    for (int i = 1; i <= 4 * MAX_A; i++) {
        fact[i] = fact[i - 1] * i;
    }

    for (int i = 0; i < N; i++) {
        m(-A[i], -B[i]) += 1;
    }
    for (int i = -MAX_A; i <= MAX_A; i++) {
        for (int j = -MAX_A; j <= MAX_A; j++) {
            m(i + 1, j) += m(i, j);
            m(i, j + 1) += m(i, j);
        }
    }

    gf ans = 0;
    for (int i = 0; i < N; i++) {
        ans += m(A[i], B[i]);
        ans -= combi(2 * A[i] + 2 * B[i], 2 * A[i]);
    }
    ans /= 2;

    return ans.n;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    cout << solve() << endl;

    return 0;
}
