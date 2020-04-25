// TDPC
// M - 家

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_R = 16;
const ll MOD = 1000000007;

ll H;
int R;
int g[MAX_R][MAX_R];
ll dp[MAX_R][MAX_R][1 << MAX_R];
ll s[MAX_R][MAX_R], sp[MAX_R][MAX_R];

void dot(ll m1[MAX_R][MAX_R], ll m2[MAX_R][MAX_R], ll out[MAX_R][MAX_R]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            out[i][j] = 0;
            for (int k = 0; k < R; k++) {
                out[i][j] += m1[i][k] * m2[k][j];
                out[i][j] %= MOD;
            }
        }
    }
    return;
}

int main() {
    ll tmp[MAX_R][MAX_R];

    cin >> H >> R;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            cin >> g[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < R; i++) {
        dp[i][i][1 << i] = 1;
    }
    for (int i = 0; i < R; i++) {
        for (int b = 0; b < (1 << R); b++) {
            for (int k = 0; k < R; k++) {
                for (int j = 0; j < R; j++) {
                    if (g[j][k] == 1 && ((b >> k) & 1) == 0) {
                        dp[i][k][b | (1 << k)] += dp[i][j][b];
                        dp[i][k][b | (1 << k)] %= MOD;
                    }
                }
            }
        }
    }

    memset(s, 0, sizeof(s));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            for (int b = 0; b < (1 << R); b++) {
                s[i][j] += dp[i][j][b];
                s[i][j] %= MOD;
            }
        }
    }

    memset(sp, 0, sizeof(sp));
    for (int i = 0; i < R; i++) {
        sp[i][i] = 1;
    }
    for (int h = H; h > 0; h >>= 1) {
        if (h & 1) {
            dot(sp, s, tmp);
            swap(sp, tmp);
        }
        dot(s, s, tmp);
        swap(s, tmp);
    }

    cout << sp[0][0] << endl;

    return 0;
}
