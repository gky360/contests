/*
[dp] C - Vacation
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

const int MAX_N = 1e5;

int N;
int abc[MAX_N + 1][3];
int dp[MAX_N + 1][3];

ll solve() {
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (k == j) {
                    continue;
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + abc[i][j]);
            }
        }
    }
    int ans = max(dp[N][0], max(dp[N][1], dp[N][2]));
    return ans;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> abc[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}
