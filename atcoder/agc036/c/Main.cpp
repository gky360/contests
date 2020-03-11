/*
[agc036] C - GP 2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e6;
const int MAX_M = 5e5;
const int MOD = 998244353;

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
    gf operator+(const gf x) const { return gf((n + x.n) % MOD); }
    gf operator-(const gf x) const { return gf((n - x.n + MOD) % MOD); }
    gf operator*(const gf x) const { return gf((1LL * n * x.n) % MOD); }
    gf operator/(const gf x) const { return *this * x.inv(); }
    gf& operator+=(const gf x) { return *this = (*this + x); }
    gf inv() const { return gf(mod_inv(n, MOD)); }
};

int N, M;
gf fact[3 * MAX_M + MAX_N + 1];

gf combi(int n, int k) {
    return (n < 0 || k < 0 || n - k < 0) ? 0
                                         : fact[n] / (fact[k] * fact[n - k]);
}

gf calc(int s, int m, int n) {
    gf ret = 0;
    for (int i = 0; i <= m; i++) {
        if ((s - i) % 2 != 0) {
            continue;
        }
        ret += combi(n, i) * combi((s - i) / 2 + n - 1, n - 1);
    }
    return ret;
}

ll solve() {
    fact[0] = 1;
    for (int i = 1; i <= 3 * MAX_M + MAX_N; i++) {
        fact[i] = fact[i - 1] * i;
    }

    gf ans = calc(3 * M, M, N) - (calc(M, M, N) - calc(M, M, N - 1)) * N;

    return ans.n;
}

int main() {
    cin >> N >> M;

    cout << solve() << endl;

    return 0;
}
