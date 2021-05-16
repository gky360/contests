/*
[arc104] D - Multiset Mean
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100;
const int MAX_K = 100;
const int MAX_S = MAX_N * MAX_N * MAX_K;

int N, K, MOD;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
};

gf dp[MAX_N + 1][MAX_S + 1];

void solve() {
    int sz = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        sz += i;
        gf ps[MAX_N + 1];
        for (int j = 0; j <= sz * K; j++) {
            int m = j % i;
            ps[m] += dp[i - 1][j];
            int lj = j - i * (K + 1);
            if (lj >= 0) {
                ps[m] -= dp[i - 1][lj];
            }
            dp[i][j] = ps[m];
        }
    }

    for (int i = 1; i <= N; i++) {
        gf ans = 0;
        for (int j = 0; j <= sz * K; j++) {
            ans += dp[i - 1][j] * dp[N - i][j];
        }
        ans = ans * (K + 1) - 1;
        cout << ans.n << endl;
    }
}

int main() {
    cin >> N >> K >> MOD;

    solve();

    return 0;
}
