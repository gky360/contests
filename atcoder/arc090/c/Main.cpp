// ARC090
// C - Candies

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100;

int N;
int a[3][MAX_N + 1];
int dp[3][MAX_N + 1];

int main() {
    cin >> N;

    memset(a, 0, sizeof(a));
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }

    cout << dp[2][N] << endl;

    return 0;
}
