/*
[dp] T - Permutation
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

const int MAX_N = 3000;
const ll MOD = 1e9 + 7;

int N;
string s;
ll dp[MAX_N][MAX_N];

ll solve() {
    for (int j = 0; j < N; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= N - i; j++) {
            if (s[i - 1] == '<') {
                (dp[i][j] += dp[i - 1][j]) %= MOD;
                (dp[i][N - i] += MOD - dp[i - 1][j]) %= MOD;
            } else {
                (dp[i][0] += dp[i - 1][j]) %= MOD;
                (dp[i][j] += MOD - dp[i - 1][j]) %= MOD;
            }
        }
        for (int j = 1; j <= N - i; j++) {
            (dp[i][j] += dp[i][j - 1]) %= MOD;
        }
    }
    return dp[N - 1][0];
}

int main() {
    cin >> N;
    cin >> s;

    cout << solve() << endl;

    return 0;
}
