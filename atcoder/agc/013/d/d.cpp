// AtCoder Grand Contest 013
// D - Piling Up

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 3000;
const ll MOD = (ll)1e9 + 7;

int N, M;
ll dp[2][MAX_N + 1];

int main() {

    ll ans;

    cin >> N >> M;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[1][i] = 1;
    }

    for (int k = 0; k < M - 1; k++) {
        for (int j = 0; j < 2; j++) {
            dp[j][N] = 0;
            for (int i = N; i > 0; i--) {
                dp[j][i] += dp[j][i - 1];
                dp[j][i] %= MOD;
            }
            for (int i = 0; i < N; i++) {
                dp[j][i] += dp[j][i + 1];
                dp[j][i] %= MOD;
            }
        }
        dp[0][0] += dp[1][0];
        dp[0][0] %= MOD;
        dp[1][0] = 0;
    }

    ans = 0;
    for (int i = 0; i < N; i++) {
        ans += dp[0][i];
        ans %= MOD;
    }
    ans *= 4;
    ans %= MOD;

    cout << ans << endl;

    return 0;

}



