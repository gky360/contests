/*
[abc180] E - Traveling Salesman among Aerial Cities
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 17;
const int INF = 1e9 + 7;

int N;
int X[MAX_N], Y[MAX_N], Z[MAX_N];
int dp[1 << MAX_N][MAX_N];

int dist(int i, int j) {
    return abs(X[i] - X[j]) + abs(Y[i] - Y[j]) + max(0, Z[j] - Z[i]);
}

ll solve() {
    for (int p = 0; p < (1 << N); p++) {
        for (int i = 0; i < N; i++) {
            dp[p][i] = INF;
        }
    }
    dp[1][0] = 0;

    for (int p = 1; p < (1 << N); p++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((p >> j) & 1) continue;
                dp[p | (1 << j)][j] =
                    min(dp[p | (1 << j)][j], dp[p][i] + dist(i, j));
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < N; i++) {
        ans = min(ans, dp[(1 << N) - 1][i] + dist(i, 0));
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
    }
    cout << solve() << endl;

    return 0;
}
