/*
[code-festival-2018-quala] C - 半分
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 50;
const int MAX_B = 60 + 1;
const ll MOD = 1e9 + 7;

int N;
ll K;
ll b[MAX_N + 1];
ll dp[MAX_N + 1][(MAX_N * MAX_B) + 1][2];

ll solve() {
    dp[0][0][0] = 1;
    for (int n = 1; n <= N; n++) {
        dp[n][0][0] = b[n] > 0 ? dp[n - 1][0][0] : 0;
        for (int k = 1; k <= MAX_B * N; k++) {
            dp[n][k][0] = dp[n][k - 1][0];
            (dp[n][k][0] += dp[n - 1][k][0]) %= MOD;
            if (k - b[n] >= 0) {
                (dp[n][k][0] += MOD - dp[n - 1][k - b[n]][0]) %= MOD;
            }
        }
    }

    for (int n = 1; n <= N; n++) {
        dp[n][0][1] = b[n] == 0 ? 1 : dp[n - 1][0][1];

        ll t = dp[n - 1][0][1];
        for (int k = 1; k <= MAX_B * N; k++) {
            (t += dp[n - 1][k][1]) %= MOD;
            if (k - b[n] - 1 >= 0) {
                (t += MOD - dp[n - 1][k - b[n] - 1][1]) %= MOD;
            }
            dp[n][k][1] = t;
            if (k - b[n] >= 0) {
                (dp[n][k][1] += dp[n - 1][k - b[n]][0]) %= MOD;
            }
        }
    }

    ll ans = dp[N][min(1LL * MAX_B * N, K)][0];
    for (int k = 0; k <= min(1LL * MAX_B * N, K); k++) {
        (ans += dp[N][k][1]) %= MOD;
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        for (; a > 0; a >>= 1) {
            b[i]++;
        }
    }

    cout << solve() << endl;

    return 0;
}
