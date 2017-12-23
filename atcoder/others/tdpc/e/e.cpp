// Typical dpr Contest
// E - 数

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_K = 10001;
const int MAX_D = 100;
const ll MOD = 1000000007;

int D, K;
string n_str;
int n[MAX_K];
ll dp[MAX_K + 1][MAX_D];

int main() {

    ll s;
    ll ans;

    cin >> D;
    cin >> n_str;
    K = n_str.length();
    for (int i = 0; i < K; i++) {
        n[i] = n_str[K - 1 - i] - '0';
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int k = 0; k < K; k++) {
        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < D; i++) {
                dp[k + 1][(i + j) % D] += dp[k][i];
                dp[k + 1][(i + j) % D] %= MOD;
            }
        }
    }

    s = 0;
    ans = 0;
    for (int k = K - 1; k >= 0; k--) {
        for (int i = 0; i < n[k]; i++) {
            ans += dp[k][(D - ((s + i) % D)) % D];
            ans %= MOD;
        }
        s = (s + n[k]) % MOD;
    }
    ans = (ans - 1 + MOD) % MOD;

    cout << ans << endl;

    return 0;

}
