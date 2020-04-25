// TDPC
// P - うなぎ

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 1000;
const int MAX_K = 50;
constexpr ll MOD = 1e9 + 7;

int N, K;
vector<int> g[MAX_N];
ll dp[MAX_N][MAX_K + 2][3], dp2[MAX_N][MAX_K + 2][3];

void dfs(int u, int par = -1) {
    vector<int> cs;

    for (int v : g[u]) {
        if (v == par) {
            continue;
        }
        dfs(v, u);
        cs.push_back(v);
    }

    int c = cs.size();
    memset(dp2, 0, sizeof(dp2));
    dp2[0][0][0] = 1;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l <= K; l++) {
                    for (int m = 0; m < 3; m++) {
                        if (j + l > K + 1) {
                            continue;
                        }
                        ll s = (dp2[i][j][k] * dp[cs[i]][l][m]) % MOD;
                        (dp2[i + 1][j + l][k] += s) %= MOD;
                        if (k == 0) {
                            if (m == 0 && j + l + 1 <= K + 1) {
                                (dp2[i + 1][j + l + 1][1] += s) %= MOD;
                            } else if (m == 1) {
                                (dp2[i + 1][j + l][1] += s) %= MOD;
                            }
                        } else if (k == 1) {
                            if (m == 0) {
                                (dp2[i + 1][j + l][2] += s) %= MOD;
                            } else if (m == 1 && j + l - 1 >= 0) {
                                (dp2[i + 1][j + l - 1][2] += s) %= MOD;
                            }
                        }
                    }
                }
            }
        }
    }
    memcpy(dp[u], dp2[c], sizeof(dp[u]));

    return;
}

int main() {
    int a, b;
    ll ans;

    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    dfs(0);

    ans = (dp[0][K][0] + dp[0][K][1] + dp[0][K][2]) % MOD;
    cout << ans << endl;

    return 0;
}
