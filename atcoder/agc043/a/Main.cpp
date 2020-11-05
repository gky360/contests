/*
[agc043] A - Range Flip Find Route
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

const int MAX_H = 100;
const int MAX_W = 100;

int H, W;
bool m[MAX_H + 1][MAX_W + 1];
int dp[MAX_H + 1][MAX_W + 1];

ll solve() {
    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = H + W;
        }
    }
    dp[0][1] = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = min(dp[i - 1][j] + (!m[i - 1][j] && m[i][j] ? 1 : 0),
                           dp[i][j - 1] + (!m[i][j - 1] && m[i][j] ? 1 : 0));
        }
    }

    ll ans = dp[H][W];
    return ans;
}

int main() {
    cin >> H >> W;
    REP(i, H) {
        string s;
        cin >> s;
        REP(j, W) {
            if (s[j] == '#') m[i + 1][j + 1] = true;
        }
    }

    cout << solve() << endl;

    return 0;
}
