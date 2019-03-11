/*
[agc028] D - Chords
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

const int MAX_N = 300;
const ll MOD = 1e9 + 7;

int N, K;
int to[2 * MAX_N];
ll fac[2 * MAX_N + 1];
ll dp[2 * MAX_N][2 * MAX_N], dp2[2 * MAX_N][2 * MAX_N];

ll solve() {
    fac[0] = 1;
    for (int i = 1; i <= 2 * MAX_N; i++) {
        fac[i] = (fac[i - 1] * (2 * i - 1)) % MOD;
    }

    ll ans = 0;
    for (int L = 2; L <= 2 * N; L += 2) {
        for (int s = 0; s + L <= 2 * N; s++) {
            int l = s, r = s + L - 1, cnt = 0;
            bool has_out = false;
            for (int j = l; j <= r; j++) {
                if (to[j] == -1) {
                    cnt++;
                } else {
                    if (to[j] < l || r < to[j]) {
                        has_out = true;
                        break;
                    }
                }
            }
            if (has_out) {
                dp[l][r] = dp2[l][r] = 0;
                continue;
            }
            dp2[l][r] = fac[cnt / 2];
            dp[l][r] = dp2[l][r];
            for (int j = l; j < r; j++) {
                (dp[l][r] += MOD - dp2[l][j] * dp[j + 1][r] % MOD) %= MOD;
            }

            (ans += dp[l][r] * fac[N - K - cnt / 2] % MOD) %= MOD;
        }
    }

    return ans;
}

int main() {
    cin >> N >> K;
    memset(to, -1, sizeof(to));
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a] = b;
        to[b] = a;
    }

    cout << solve() << endl;

    return 0;
}
