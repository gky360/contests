/*
[abc154] E - Almost Everywhere Zero
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_L = 100;
const int MAX_K = 3;

string N;
int K;
int dp[MAX_K + 1][MAX_L + 1][2];

ll solve() {
    int L = N.size();
    dp[0][0][0] = 1;

    for (int i = 0; i < L; i++) {
        int n = N[i] - '0';
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int j = 0; j <= (smaller ? 9 : n); j++) {
                for (int k = 0; k <= K; k++) {
                    int nk = k + (j > 0 ? 1 : 0);
                    if (nk <= K) {
                        dp[nk][i + 1][smaller || (j < n)] += dp[k][i][smaller];
                    }
                }
            }
        }
    }

    return dp[K][L][0] + dp[K][L][1];
}

int main() {
    cin >> N;
    cin >> K;

    cout << solve() << endl;

    return 0;
}
