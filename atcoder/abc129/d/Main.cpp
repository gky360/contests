/*
[abc129] D - Lamp
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_HW = 2000;

int H, W;
bool m[MAX_HW + 2][MAX_HW + 2];
int d[4][MAX_HW + 2][MAX_HW + 2];

ll solve() {
    for (int j = 1; j <= W; j++) {
        d[0][0][j] = 0;
        for (int i = 1; i <= H; i++) {
            d[0][i][j] = m[i][j] ? i : d[0][i - 1][j];
        }
        d[2][H + 1][j] = H + 1;
        for (int i = H; i > 0; i--) {
            d[2][i][j] = m[i][j] ? i : d[2][i + 1][j];
        }
    }
    for (int i = 1; i <= H; i++) {
        d[1][i][W + 1] = W + 1;
        for (int j = W; j > 0; j--) {
            d[1][i][j] = m[i][j] ? j : d[1][i][j + 1];
        }
        d[3][i][0] = 0;
        for (int j = 1; j <= W; j++) {
            d[3][i][j] = m[i][j] ? j : d[3][i][j - 1];
        }
    }

    int ans = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (!m[i][j]) {
                int cand =
                    d[2][i][j] - d[0][i][j] + d[1][i][j] - d[3][i][j] - 3;
                ans = max(ans, cand);
            }
        }
    }
    return ans;
}

int main() {
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= W; j++) {
            m[i][j] = (s[j - 1] == '#');
        }
    }

    cout << solve() << endl;

    return 0;
}
