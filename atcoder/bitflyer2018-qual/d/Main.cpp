/*
[bitflyer2018-qual] D - ハンコ
*/

#include <algorithm>
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

const int MAX_N = 1000;
const int MAX_M = 1000;

int H, W;
int N, M;
string a[MAX_N];
int dp[2 * MAX_N + 2][2 * MAX_M + 2];

ll solve() {
    int LH = min(2 * N, H);
    int LW = min(2 * M, W);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == '#') {
                dp[i][j]++;
                dp[i + LH - N + 1][j]--;
                dp[i][j + LW - M + 1]--;
                dp[i + LH - N + 1][j + LW - M + 1]++;
            }
        }
    }
    for (int i = 1; i <= LH; i++) {
        for (int j = 0; j <= LW; j++) {
            dp[i][j] += dp[i - 1][j];
        }
    }
    for (int j = 1; j <= LW; j++) {
        for (int i = 0; i <= LH; i++) {
            dp[i][j] += dp[i][j - 1];
        }
    }

    ll ans = 0;
    for (int i = 0; i < LH; i++) {
        for (int j = 0; j < LW; j++) {
            if (dp[i][j] > 0) {
                ans++;
            }
        }
    }
    ll sh = 0;
    for (int j = 0; j <= LW; j++) {
        if (dp[N][j] > 0) {
            sh++;
        }
    }
    ll sw = 0;
    for (int i = 0; i <= LH; i++) {
        if (dp[i][M] > 0) {
            sw++;
        }
    }
    ll dh = max(0, H - 2 * N);
    ll dw = max(0, W - 2 * M);
    ans += sh * dh + sw * dw + (dp[N][M] > 0 ? 1 : 0) * dh * dw;

    return ans;
}

int main() {
    cin >> H >> W;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
