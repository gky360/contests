/*
[dp] D - Knapsack 1
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

const int MAX_N = 100;
const int MAX_W = 1e5;

int N, W;
int w[MAX_N + 1], v[MAX_N + 1];
ll dp[MAX_N + 1][MAX_W + 1];

ll solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = (j - w[i] >= 0)
                           ? max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])
                           : dp[i - 1][j];
        }
    }

    return dp[N][W];
}

int main() {
    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    cout << solve() << endl;

    return 0;
}
