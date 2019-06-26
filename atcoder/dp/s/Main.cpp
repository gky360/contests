/*
[dp] S - Digit Sum
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 1e5;
const int MAX_D = 100;
const ll MOD = 1e9 + 7;

string K;
int N;
int D;
ll dp[MAX_N + 1][2][MAX_D];

ll solve() {
    dp[0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < D; k++) {
                int lim = (j == 1) ? 9 : (K[i] - '0');
                for (int l = 0; l <= lim; l++) {
                    (dp[i + 1][j || (l < lim)][(k + l) % D] += dp[i][j][k]) %=
                        MOD;
                }
            }
        }
    }

    return (dp[N][0][0] + dp[N][1][0] + MOD - 1) % MOD;
}

int main() {
    cin >> K;
    cin >> D;
    N = K.length();

    cout << solve() << endl;

    return 0;
}
