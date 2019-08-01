/*
[yahoo-procon2019-qual] D - Ears
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_L = 2e5;
const ll INF = 1e18;

int L;
int A[MAX_L + 1];
ll dp[MAX_L + 1][5];

ll solve() {
    for (int i = 0; i <= L; i++) {
        for (int j = 0; j < 5; j++) {
            dp[i][j] = INF;
        }
    }

    for (int j = 0; j < 5; j++) {
        dp[0][j] = 0;
        for (int i = 1; i <= L; i++) {
            ll x;
            switch (j) {
                case 1:
                case 3:
                    x = (A[i] == 0) ? 2 : (A[i] % 2);
                    break;
                case 2:
                    x = (A[i] + 1) % 2;
                    break;
                default:
                    x = A[i];
            }
            dp[i][j] = min(dp[i - 1][j] + x, j > 0 ? dp[i][j - 1] : INF);
        }
    }

    return dp[L][4];
}

int main() {
    cin >> L;
    for (int i = 1; i <= L; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
