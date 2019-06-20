/*
[dp] M - Candies
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

const int MAX_N = 100;
const int MAX_K = 1e5;
const ll MOD = 1e9 + 7;

int N, K;
int a[MAX_N];
ll dp[MAX_N + 1][MAX_K + 2];

ll solve() {
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            (dp[i][j] += dp[i - 1][j]) %= MOD;
            (dp[i][min(K + 1, j + a[i - 1] + 1)] += MOD - dp[i - 1][j]) %= MOD;
        }
        for (int j = 0; j <= K; j++) {
            (dp[i][j + 1] += dp[i][j]) %= MOD;
        }
    }

    return dp[N][K];
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
