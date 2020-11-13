/*
[abc159] F - Knapsack for All Segments
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

const int MAX_N = 3000;
const int MAX_S = 3000;
const int MOD = 998244353;

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

int N, S;
int A[MAX_N];
gf dp[MAX_N][MAX_S + 1];

ll solve() {
    dp[0][0] = dp[0][A[0]] = 1;
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i][A[i]] = 1;
        for (int j = 0; j <= S; j++) {
            dp[i][j] += dp[i - 1][j];
            if (j - A[i] >= 0) dp[i][j] += dp[i - 1][j - A[i]];
        }
    }

    gf ans = 0;
    for (int i = 0; i < N; i++) {
        ans += dp[i][S];
    }

    return ans.n;
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
