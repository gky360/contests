/*
[dp] H - Grid 1
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

const int MAX_H = 1000;
const int MAX_W = 1000;
const ll MOD = 1e9 + 7;

int H, W;
char a[MAX_H + 1][MAX_W + 1];
int dp[MAX_H + 1][MAX_W + 1];

ll solve() {
    dp[0][1] = 1;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] =
                (a[i][j] == '#') ? 0 : (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    return dp[H][W];
}

int main() {
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> a[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}
