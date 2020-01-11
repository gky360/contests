/*
[abc003] D - AtCoder社の冬
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_R = 30;
const int MAX_C = 30;
const int MOD = 1e9 + 7;

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

int R, C;
int H, W;
int D, L;
gf fact[MAX_R * MAX_C + 1];

gf combi(int n, int k) {
    return (n < 0 || k < 0 || n - k < 0) ? 0
                                         : fact[n] / (fact[k] * fact[n - k]);
}

gf rect(int h, int w) {
    return (h < 0 || w < 0) ? 0 : combi(h * w, D) * combi(h * w - D, L);
}

ll solve() {
    fact[0] = 1;
    for (int i = 1; i <= R * C; i++) {
        fact[i] = fact[i - 1] * i;
    }

    gf p0 = rect(H, W);
    gf p1 = rect(H - 1, W) * 2 + rect(H, W - 1) * 2;
    gf p2 = rect(H - 1, W - 1) * 4 + rect(H - 2, W) + rect(H, W - 2);
    gf p3 = rect(H - 2, W - 1) * 2 + rect(H - 1, W - 2) * 2;
    gf p4 = rect(H - 2, W - 2);

    gf ans = (p0 - p1 + p2 - p3 + p4) * (R - H + 1) * (C - W + 1);

    return ans.n;
}

int main() {
    cin >> R >> C;
    cin >> H >> W;
    cin >> D >> L;

    cout << solve() << endl;

    return 0;
}
