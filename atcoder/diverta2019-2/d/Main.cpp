/*
[diverta2019-2] D - Squirrel Merchant
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int P = 2;
const int Q = 3;
const int MAX_N = 5000;
const int MAX_C = 5000;

int N;
int c[P][Q];
ll dp[MAX_N * MAX_C + 1];

ll solve() {
    ll W = N;
    for (int p = 0; p < P; p++) {
        int w[3], v[3];
        for (int q = 0; q < Q; q++) {
            w[q] = c[p][q];
            v[q] = c[p ^ 1][q] - c[p][q];
        }

        memset(dp, 0, sizeof(dp));
        for (int q = 1; q <= Q; q++) {
            for (int i = w[q - 1]; i <= W; i++) {
                dp[i] = max(dp[i], dp[i - w[q - 1]] + v[q - 1]);
            }
        }
        W += dp[W];
    }

    return W;
}

int main() {
    cin >> N;
    for (int p = 0; p < P; p++) {
        for (int q = 0; q < Q; q++) {
            cin >> c[p][q];
        }
    }

    cout << solve() << endl;

    return 0;
}
