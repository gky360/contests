/*
[arc096] E - Everything on It
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 3000;

int N, MOD;

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

gf p2[MAX_N * MAX_N + 1];
gf pp2[MAX_N + 1];
gf stirling2[MAX_N + 1][MAX_N + 1];

gf f2(int i, int j) {
    return (stirling2[i][j] + stirling2[i][j + 1] * (j + 1)) * p2[(N - i) * j] *
           pp2[N - i];
}

gf f1(int i) {
    gf ret = 0;
    for (int j = 0; j <= i; j++) {
        ret += f2(i, j);
    }
    return ret;
}

ll solve() {
    p2[0] = 1;
    for (int i = 1; i <= N * N; i++) {
        p2[i] = p2[i - 1] * 2;
    }

    pp2[0] = 2;
    for (int i = 1; i <= N; i++) {
        pp2[i] = pp2[i - 1] * pp2[i - 1];
    }

    stirling2[0][0] = 1;
    for (int n = 1; n <= N; n++) {
        for (int k = 1; k <= n; k++) {
            stirling2[n][k] = stirling2[n - 1][k - 1] + stirling2[n - 1][k] * k;
        }
    }

    gf ans = 0;
    gf nci = 1;
    for (int i = 0; i <= N; i++) {
        ans += f1(i) * nci * ((i & 1) ? -1 : 1);
        nci = nci * (N - i) / (i + 1);
    }

    return ans.n;
}

int main() {
    cin >> N >> MOD;

    cout << solve() << endl;

    return 0;
}
