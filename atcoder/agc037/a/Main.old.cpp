/*
[agc037] A - Dividing a String
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;

int N;
string S;
int dp[3][MAX_N + 1];

ll solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 2; j++) {
            if (i - j < 0) {
                continue;
            }
            dp[j][i] = dp[3 - j][i - j] + 1;
            if (i - 2 * j >= 0 &&
                S.substr(i - 2 * j, j) != S.substr(i - j, j)) {
                dp[j][i] = max(dp[j][i], dp[j][i - j] + 1);
            }
        }
    }

    return max(dp[1][N], dp[2][N]);
}

int main() {
    cin >> S;
    N = S.length();

    cout << solve() << endl;

    return 0;
}
