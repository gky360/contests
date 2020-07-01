/*
[abc145] F - Laminate
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 300;
const int MAX_K = MAX_N;
const ll INF = 1e18;

int N, K;
int H[MAX_N + 2];
ll dp[MAX_N + 2][MAX_K + 1];

ll solve() {
    for (int i = 1; i <= N + 1; i++) {
        for (int k = 0; k <= K; k++) {
            dp[i][k] = k == 0 ? INF : dp[i][k - 1];
            for (int j = max(0, i - k - 1); j < i; j++) {
                dp[i][k] =
                    min(dp[i][k], dp[j][k - (i - j - 1)] + max(0, H[i] - H[j]));
            }
        }
    }

    ll ans = dp[N + 1][K];
    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    cout << solve() << endl;

    return 0;
}
