/*
[abc175] E - Picking Goods
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

const int MAX_R = 3000;
const int MAX_C = 3000;
const int MAX_K = 2e5;

int R, C, K;
ll m[MAX_R + 1][MAX_C + 1];
ll dp[MAX_R + 1][MAX_C + 1][4];

ll solve() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            dp[i][j][0] = max(dp[i][j - 1][0], dp[i - 1][j][3]);
            for (int k = 1; k <= 3; k++) {
                dp[i][j][k] = max(dp[i][j][k - 1], dp[i][j - 1][k]);
            }
            for (int k = 3; k > 0; k--) {
                dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + m[i][j]);
            }
        }
    }

    ll ans = dp[R][C][3];
    return ans;
}

int main() {
    cin >> R >> C >> K;
    REP(i, K) {
        int r, c, v;
        cin >> r >> c >> v;
        m[r][c] = v;
    }

    cout << solve() << endl;

    return 0;
}
