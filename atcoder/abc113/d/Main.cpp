/*
[abc113] D - Number of Amidakuji
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

const int MAX_H = 100;
const int MAX_W = 8;
const ll MOD = 1e9 + 7;

int H, W, K;
int dp[MAX_H + 1][MAX_W + 2];

ll solve() {
    dp[0][1] = 1;
    for (int i = 0; i < H; i++) {
        for (int pat = 0; pat < (1 << W); pat += 2) {
            if (pat & (pat << 1)) {
                continue;
            }
            for (int j = 1; j <= W; j++) {
                if (pat & (1 << (j - 1))) {
                    (dp[i + 1][j - 1] += dp[i][j]) %= MOD;
                } else if (pat & (1 << j)) {
                    (dp[i + 1][j + 1] += dp[i][j]) %= MOD;
                } else {
                    (dp[i + 1][j] += dp[i][j]) %= MOD;
                }
            }
        }
    }
    return dp[H][K];
}

int main() {
    cin >> H >> W >> K;
    cout << solve() << endl;

    return 0;
}
