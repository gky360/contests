// TDPC
// Q - 連結

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 510;
const int MAX_M = 8;
const int MAX_L = 100;
constexpr int MOD = 1e9 + 7;

int N, L;
bool w[MAX_M + 1][1 << MAX_M];
int dp[MAX_L + 1][1 << (MAX_M - 1)][1 << MAX_M];

int main() {
    cin >> N >> L;
    memset(w, 0, sizeof(w));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int b = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            b |= (s[j] - '0') << j;
        }
        w[s.size()][b] = true;
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0][1] = 1;
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < (1 << (MAX_M - 1)); j++) {
            for (int k = 0; k < (1 << MAX_M); k++) {
                for (int l = 0; l < 2; l++) {
                    int nj = ((j << 1) & ((1 << (MAX_M - 1)) - 1)) | l;
                    int nk = (k << 1) & ((1 << MAX_M) - 1);
                    for (int m = 1; m <= MAX_M; m++) {
                        int b = ((j << 1) | l) & ((1 << m) - 1);
                        if ((k >> (m - 1)) & 1 && w[m][b]) {
                            nk |= 1;
                            break;
                        }
                    }
                    (dp[i + 1][nj][nk] += dp[i][j][k]) %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < (1 << (MAX_M - 1)); j++) {
        for (int k = 0; k < (1 << (MAX_M - 1)); k++) {
            (ans += dp[L][j][(k << 1) + 1]) %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
