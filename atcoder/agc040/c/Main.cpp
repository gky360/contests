/*
[agc040] C - Neither AB nor BA
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MOD = 998244353;

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

const int MAX_N = 1e7;

int N;
gf pow2[MAX_N + 1], pow3[MAX_N + 1], nc[MAX_N + 1];

ll solve() {
    pow2[0] = pow3[0] = nc[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow2[i] = pow2[i - 1] * 2;
        pow3[i] = pow3[i - 1] * 3;
        nc[i] = nc[i - 1] * (N - i + 1) / i;
    }

    gf ans = pow3[N];
    for (int i = N / 2 + 1; i <= N; i++) {
        ans -= nc[i] * pow2[N - i] * 2;
    }

    return ans.n;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
