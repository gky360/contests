/*
[abc141] E - Who Says a Pun?
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 5e3;

int N;
string S;
int dp[MAX_N][MAX_N];

ll solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int pre = i > 0 ? dp[i - 1][j - 1] : 0;
            dp[i][j] = S[i] == S[j] ? pre + 1 : 0;
            if (i + dp[i][j] <= j) {
                ans = max(ans, dp[i][j]);
            }
        }
    }

    return ans;
}

int main() {
    cin >> N;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
