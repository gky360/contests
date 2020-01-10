/*
[abc024] D - 動的計画法
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

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

int A, B, C;

pii solve() {
    gf a = A, b = B, c = C;

    gf m = (a * b + a * c - b * c).inv();
    gf row = (b * c - a * c) * m;
    gf col = (b * c - a * b) * m;

    return {row.n, col.n};
}

int main() {
    cin >> A;
    cin >> B;
    cin >> C;

    pii ans = solve();
    cout << ans.first << " " << ans.second << endl;

    return 0;
}
