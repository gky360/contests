// TDPC
// O - 文字列

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

constexpr int AZ = 'z' - 'a' + 1;
constexpr int MAX_F = 10;
constexpr int MAX_N = AZ * MAX_F;
constexpr int MOD = 1000000007;

inline int adda(int &a, int b) { return a = (0LL + a + b) % MOD; }
inline int mula(int &a, int b) { return a = 1LL * a * b % MOD; }

int f[AZ];
int C;
int sum[AZ + 1];
int comb[MAX_N + 2][MAX_F + 1];
int dp[AZ + 1][MAX_N];

int main() {
    int tmp;

    sum[0] = 0;
    for (int i = 0; i < AZ; i++) {
        cin >> f[i];
    }
    sort(f, f + AZ);
    C = AZ - (upper_bound(f, f + AZ, 0) - f);
    reverse(f, f + AZ);
    sum[0] = 0;
    for (int i = 0; i < AZ; i++) {
        sum[i + 1] = sum[i] + f[i];
    }

    for (int i = 0; i <= MAX_N; i++) {
        comb[i][0] = 1;
    }
    for (int j = 0; j <= MAX_F; j++) {
        comb[0][j] = 1;
    }
    comb[0][0] = 1;
    for (int i = 1; i < MAX_N + 2; i++) {
        comb[i][0] = 1;
        for (int j = 1; j < min(i, MAX_F + 1); j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
        if (i <= MAX_F) {
            comb[i][i] = 1;
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j <= sum[i]; j++) {
            for (int k = 1; k <= f[i]; k++) {
                for (int l = 0; l <= min(j, k); l++) {
                    tmp = dp[i][j];
                    mula(tmp, comb[f[i] - 1][k - 1]);
                    mula(tmp, comb[j][l]);
                    mula(tmp, comb[sum[i] + 1 - j][k - l]);
                    adda(dp[i + 1][j - l + f[i] - k], tmp);
                }
            }
        }
    }

    cout << dp[C][0] << endl;

    return 0;
}
