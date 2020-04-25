// TDPC
// I - イウィ

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 300;

string s;
int N;
bool r[MAX_N + 1][MAX_N + 1];
int dp[MAX_N];

int main() {
    cin >> s;
    N = s.length();

    memset(r, 0, sizeof(r));
    for (int i = 0; i <= N; i++) {
        r[i][i] = true;
    }

    for (int l = 3; l <= N; l++) {
        for (int i = 0; i + l <= N; i++) {
            int j = i + l;
            if (s[i] != 'i' || s[j - 1] != 'i') {
                continue;
            }
            for (int k = i + 1; k < j - 1; k++) {
            }
            for (int k = i + 1; k < j - 1; k++) {
                if ((r[i][k] && r[k][j]) ||
                    (s[k] == 'w' && r[i + 1][k] && r[k + 1][j - 1])) {
                    r[i][j] = true;
                    break;
                }
            }
        }
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j <= i - 3; j++) {
            if (r[j][i]) {
                dp[i] = max(dp[i], dp[j] + (i - j) / 3);
            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}
