// TDPC
// L - 猫

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 1000;
const ll INF = 1e17;

int N;
int f[MAX_N][MAX_N];
ll dp[MAX_N][MAX_N];

int main() {
    ll m, s;
    ll ans;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> f[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < N; i++) {
        m = -INF;
        for (int j = 0; j <= i; j++) {
            m = max(m, dp[i - 1][j]);
            dp[i][j] = m;
        }
        s = 0;
        for (int j = i; j >= 0; j--) {
            s += f[i][j];
            dp[i][j] += s;
        }
    }

    ans = -INF;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[N - 1][i]);
    }
    ans *= 2;

    cout << ans << endl;

    return 0;
}
