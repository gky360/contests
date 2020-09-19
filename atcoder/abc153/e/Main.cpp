/*
[abc153] E - Crested Ibis vs Monster
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e3;
const int MAX_H = 1e4;
const int MAX_A = 1e4;
const int INF = 1e9;

int H, N;
int A[MAX_N + 1], B[MAX_N + 1];
int dp[MAX_N + 1][2 * MAX_H + 1];

ll solve() {
    dp[0][0] = 0;
    for (int j = 1; j <= H + MAX_A; j++) {
        dp[0][j] = INF;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= H + MAX_A; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - A[i] >= 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - A[i]] + B[i]);
            }
        }
    }

    int ans = INF;
    for (int j = H; j <= H + MAX_A; j++) {
        ans = min(ans, dp[N][j]);
    }
    return ans;
}

int main() {
    cin >> H >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }

    cout << solve() << endl;

    return 0;
}
