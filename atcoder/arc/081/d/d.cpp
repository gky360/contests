// AtCoder Regular Contest 081
// D - Coloring Dominoes

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 52;
const ll MOD = 1000000007;

int N;
string s[2];
ll dp[2][MAX_N];

int main() {

    cin >> N;
    cin >> s[0];
    cin >> s[1];

    if (s[0][0] == s[1][0]) {
        dp[0][0] = 3;
        dp[1][0] = 0;
    } else {
        dp[0][0] = 3;
        dp[1][0] = 6;
    }

    for (int i = 1; i < N; i++) {
        if (s[0][i] == s[1][i]) {
            dp[0][i] = ((2 * dp[0][i - 1]) % MOD + dp[1][i - 1] % MOD) % MOD;
            dp[1][i] = 0;
        } else if (s[0][i] != s[0][i - 1] && s[1][i] != s[1][i - 1]) {
            dp[0][i] = 0;
            dp[1][i] = ((2 * dp[0][i - 1]) % MOD + (3 * dp[1][i - 1]) % MOD) % MOD;
        } else {
            dp[0][i] = 0;
            dp[1][i] = dp[1][i - 1];
        }
    }

    ll ans = (dp[0][N - 1] + dp[1][N - 1]) % MOD;
    cout << ans << endl;

    return 0;

}



