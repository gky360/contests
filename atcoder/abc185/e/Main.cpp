/*
[abc185] E - Sequence Matching
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

const int MAX_N = 1000;
const int MAX_M = 1000;
const int INF = 1e9;

int N, M;
int A[MAX_N], B[MAX_M];
int dp[MAX_N + 1][MAX_M + 1];

ll solve() {
    REP(i, N + 1) REP(j, M + 1) dp[i][j] = INF;
    dp[0][0] = 0;
    REP(i, N + 1) REP(j, M + 1) {
        if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        if (i > 0 && j > 0)
            dp[i][j] = min(dp[i][j],
                           dp[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 0 : 1));
    }

    ll ans = dp[N][M];
    return ans;
}

int main() {
    cin >> N >> M;
    REP(i, N) cin >> A[i];
    REP(i, M) cin >> B[i];

    cout << solve() << endl;

    return 0;
}
