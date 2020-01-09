/*
[abc132] D - Blue and Red Balls
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 2000;
const int MOD = 1e9 + 7;

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
    gf operator*(const gf x) const { return gf((1LL * n * x.n) % MOD); }
    gf operator/(const gf x) const { return *this * x.inv(); }
    gf inv() const { return gf(mod_inv(n, MOD)); }
};

int N, K;
gf fact[MAX_N + 1];

gf c(int n, int k) {
    return (n < 0 || k < 0 || n - k < 0) ? 0
                                         : fact[n] / (fact[k] * fact[n - k]);
}

void solve() {
    if (N == K) {
        cout << 1 << endl;
        for (int i = 2; i <= K; i++) {
            cout << 0 << endl;
        }
        return;
    }

    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i;
    }

    for (int i = 1; i <= K; i++) {
        cout << (c(K - 1, i - 1) * c(N - K + 1, i)).n << endl;
    }
}

int main() {
    cin >> N >> K;

    solve();

    return 0;
}
