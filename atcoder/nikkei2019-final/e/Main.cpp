/*
[nikkei2019-final] E - Erasure
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 5000;
const ll MOD = 1e9 + 7;

int N, K;
ll dp[MAX_N + 1][MAX_N + 1];
ll p2[MAX_N + 1];

ll solve() {
    p2[0] = 1;
    for (int i = 0; i <= N; i++) {
        p2[i + 1] = (p2[i] << 1) % MOD;
    }

    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            (dp[i + 1][j] += dp[i][j] * p2[max(0, i - j - K)]) %= MOD;
            (dp[i + 1][i + 1] +=
             dp[i][j] * (p2[max(0, i + 1 - K)] - p2[max(0, i - j - K)] + MOD) %
             MOD) %= MOD;
        }
    }

    return dp[N][N];
}

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
