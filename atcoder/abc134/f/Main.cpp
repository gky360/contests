/*
[abc134] F - Permutation Oddness
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 50;
const int MAX_K = MAX_N * MAX_N;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(const gf x) const { return gf((n + x.n) % MOD); }
    gf operator*(const gf x) const { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(const gf x) { return *this = (*this + x); }
};

int N, K;
gf dp[MAX_N + 1][MAX_N + 1][MAX_K + 1];

ll solve() {
    dp[0][0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 2 * j; k <= N * N; k++) {
                dp[i][j][k] = gf(2 * j + 1) * dp[i - 1][j][k - 2 * j];
                if (j + 1 <= N) {
                    dp[i][j][k] +=
                        gf((j + 1) * (j + 1)) * dp[i - 1][j + 1][k - 2 * j];
                }
                if (j - 1 >= 0) {
                    dp[i][j][k] += dp[i - 1][j - 1][k - 2 * j];
                }
            }
        }
    }

    return dp[N][0][K].n;
}

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
