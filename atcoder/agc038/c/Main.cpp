/*
[agc038] C - LCMs
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 200000;
const int MAX_A = 1000000;
const int MOD = 998244353;

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

int N;
int A[MAX_N];
gf w[MAX_A + 1];
gf cnt[MAX_A + 1];

ll solve() {
    for (int i = 1; i <= MAX_A; i++) {
        w[i] += gf(1) / i;
        for (int j = i * 2; j <= MAX_A; j += i) {
            w[j] -= w[i];
        }
    }

    for (int i = 0; i < N; i++) {
        cnt[A[i]] += 1;
    }

    gf ans = 0;
    for (int i = 1; i <= MAX_A; i++) {
        gf s = 0;
        for (int j = i; j <= MAX_A; j += i) {
            s += cnt[j] * j;
        }
        ans += w[i] * s * s;
    }

    for (int i = 0; i < N; i++) {
        ans -= A[i];
    }
    ans /= 2;

    return ans.n;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
