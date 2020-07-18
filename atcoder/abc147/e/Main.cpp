/*
[abc147] E - Balanced Path
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_H = 80;
const int MAX_W = 80;
const int MAX_AB = 80;
const int Z = (MAX_H + MAX_W) * MAX_AB / 2;
const int INF = 1e9;

int H, W;
int A[MAX_H][MAX_W], B[MAX_H][MAX_W];
bitset<Z * 2 + 1> dp[MAX_H + 1][MAX_W + 1];

ll solve() {
    dp[0][1][Z] = 1;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            bitset<Z* 2 + 1> x = dp[i - 1][j] | dp[i][j - 1];
            int d = abs(A[i - 1][j - 1] - B[i - 1][j - 1]);
            dp[i][j] = (x >> d) | (x << d);
        }
    }

    int ans = INF;
    for (int z = 0; z < 2 * Z + 1; z++) {
        if (dp[H][W][z]) {
            ans = min(ans, abs(z - Z));
        }
    }

    return ans;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> B[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}
