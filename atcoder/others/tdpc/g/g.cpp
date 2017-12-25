// TDPC
// G - 辞書順

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 1000000;
const int MAX_K = 1e18;
const int AZ = 26;
const ll INF = MAX_K + 1;

string s;
int N;
ll K;
ll dp[MAX_N + 1];
int nx[MAX_N + 1][AZ];

int main() {
    string ans;

    cin >> s;
    cin >> K;
    N = s.length();

    for (int j = 0; j < AZ; j++) {
        nx[N][j] = N;
    }
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < AZ; j++) {
            nx[i][j] = (s[i] == ('a' + j) ? i : nx[i + 1][j]);
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        dp[i] = 1;
        for (int j = 0; j < AZ; j++) {
            dp[i] = min(INF, dp[i] + dp[nx[i + 1][j]]);
        }
    }

    for (int i = 0; i < N && K > 0;) {
        int j = 0;
        for (; j < AZ; j++) {
            int r = nx[i][j];
            if (dp[r] >= K) {
                ans += ('a' + j);
                i = r + 1;
                K--;
                break;
            }
            K -= dp[r];
        }
        if (j == AZ) {
            cout << "Eel" << endl;
            return 0;
        }
    }

    cout << ans << endl;

    return 0;
}
