/*
[dp] J - Sushi
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 300;

int N;
int a[MAX_N];

double solve() {
    vector<vector<vector<double>>> dp(
        N + 1, vector<vector<double>>(N + 1, vector<double>(N + 1)));
    int cnt[4];

    for (int j = 1; j <= 3; j++) {
        cnt[j] = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] >= j) {
                cnt[j]++;
            }
        }
    }

    dp[0][0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j][k] = N;
                if (k > 0) {
                    dp[i][j][k] += dp[i][j][k - 1] * k;
                }
                if (j > k) {
                    dp[i][j][k] += dp[i][j - 1][k] * (j - k);
                }
                if (i > j) {
                    dp[i][j][k] += dp[i - 1][j][k] * (i - j);
                }
                dp[i][j][k] /= i;
            }
        }
    }

    return dp[cnt[1]][cnt[2]][cnt[3]];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << setprecision(16) << solve() << endl;

    return 0;
}
