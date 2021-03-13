/*
[m-solutions2020] E - M's Solution
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 15;
const ll INF = 1e18;

int N;
ll X[MAX_N], Y[MAX_N], P[MAX_N];
ll c[1 << MAX_N];
ll dp[1 << MAX_N][MAX_N + 1];

void solve() {
    for (int b = 1; b < (1 << N); b++) {
        c[b] = INF;
        REP(i, N) {
            if (((b >> i) & 1) == 0) continue;
            ll x = 0, y = 0;
            REP(j, N) {
                if (((b >> j) & 1) == 0) continue;
                x += abs(X[j] - X[i]) * P[j];
                y += abs(Y[j] - Y[i]) * P[j];
            }
            c[b] = min(c[b], min(x, y));
        }
    }

    REP(b, 1 << N) {
        dp[b][0] = INF;
        for (int s = b;; s = (s - 1) & b) {
            ll ret = 0;
            REP(i, N) {
                if ((b >> i) & 1) {
                    ret += ((s >> i) & 1) ? abs(X[i]) * P[i] : abs(Y[i]) * P[i];
                }
            }
            dp[b][0] = min(dp[b][0], ret);
            if (s == 0) break;
        }
    }
    cout << dp[(1 << N) - 1][0] << endl;

    for (int k = 1; k <= N; k++) {
        REP(b, 1 << N) {
            dp[b][k] = INF;
            for (int s = b;; s = (s - 1) & b) {
                dp[b][k] = min(dp[b][k], dp[b - s][k - 1] + c[s]);
                if (s == 0) break;
            }
        }
        cout << dp[(1 << N) - 1][k] << endl;
    }
}

int main() {
    cin >> N;
    REP(i, N) cin >> X[i] >> Y[i] >> P[i];

    solve();

    return 0;
}
