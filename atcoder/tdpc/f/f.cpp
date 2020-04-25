// TDPC
// F - 準急

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 1000000;
const ll MOD = 1000000007;

int N, K;
ll dp[MAX_N + 1][2];

int main() {
    ll s;

    cin >> N >> K;

    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    dp[1][0] = 1;
    for (int i = 2; i <= N; i++) {
        s = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        if (i - K >= 0) {
            dp[i][0] = (s - dp[i - K][1] + MOD) % MOD;
        } else {
            dp[i][0] = s;
        }
        dp[i][1] = s;
    }

    cout << dp[N][0] << endl;

    return 0;
}
