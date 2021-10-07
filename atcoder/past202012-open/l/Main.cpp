/*
[past202012-open] L - Collecting T
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

const int MAX_N = 100;

int N;
string S;
string T;
int dp[MAX_N + 1][MAX_N + 1];

ll solve() {
    for (int len = 1; len <= N; len++) {
        for (int l = 0, r = len; r <= N; l++, r++) {
            dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
            if (S[l] == T[0] && S[r - 1] == T[2]) {
                for (int m = l + 1; m < r - 1; m++) {
                    if (S[m] == T[1] && dp[l + 1][m] * 3 == m - (l + 1) &&
                        dp[m + 1][r - 1] * 3 == r - 1 - (m + 1)) {
                        dp[l][r] = max(dp[l][r], (r - l) / 3);
                    }
                }
            }
            for (int m = l + 1; m < r; m++) {
                dp[l][r] = max(dp[l][r], dp[l][m] + dp[m][r]);
            }
        }
    }

    ll ans = dp[0][N];
    return ans;
}

int main() {
    cin >> N;
    cin >> S;
    cin >> T;

    cout << solve() << endl;

    return 0;
}
