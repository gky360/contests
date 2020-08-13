/*
[abc149] D - Prediction and Restriction
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N, K;
int C[3];  // R, S, P
string T;

int judge(char c, int j) {
    return ((c == 's' && j == 0) || (c == 'p' && j == 1) ||
            (c == 'r' && j == 2))
               ? C[j]
               : 0;
}

int calc(int k) {
    int dp[3][MAX_N + 1];
    dp[0][0] = dp[1][0] = dp[2][0] = 0;

    int i, idx;
    for (i = 0, idx = k; idx < N; i++, idx += K) {
        for (int j = 0; j < 3; j++) {
            int pre = 0;
            if (j == 0) {
                pre = max(dp[1][i], dp[2][i]);
            } else if (j == 1) {
                pre = max(dp[2][i], dp[0][i]);
            } else if (j == 2) {
                pre = max(dp[0][i], dp[1][i]);
            }
            dp[j][i + 1] = pre + judge(T[idx], j);
        }
    }
    return max(max(dp[0][i], dp[1][i]), dp[2][i]);
}

ll solve() {
    ll ans = 0;
    for (int k = 0; k < K; k++) {
        ans += calc(k);
    }

    return ans;
}

int main() {
    cin >> N >> K;
    cin >> C[0] >> C[1] >> C[2];
    cin >> T;

    cout << solve() << endl;

    return 0;
}
