/*
[tenka1-2019] C - Stones
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 2e5;
const int INF = 1e8;

int N;
string S;
int dp[MAX_N][2];

ll solve() {
    dp[0][0] = (S[0] == '.') ? 0 : 1;
    dp[0][1] = (S[0] == '#') ? 0 : 1;

    for (int i = 1; i < N; i++) {
        int c = (S[i] == '.') ? 0 : 1;
        for (int k = 0; k < 2; k++) {
            dp[i][k] = INF;
            for (int j = 0; j < 2; j++) {
                if (j == 1 && k == 0) {
                    continue;
                }
                dp[i][k] = min(dp[i][k], dp[i - 1][j] + (k == c ? 0 : 1));
            }
        }
    }

    return min(dp[N - 1][0], dp[N - 1][1]);
}

int main() {
    cin >> N;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
