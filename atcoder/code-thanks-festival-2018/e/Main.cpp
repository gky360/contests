/*
[code-thanks-festival-2018] E - Union
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

const int MAX_T = 300;
const int MAX_A = 300;
const int U = MAX_T + 10;
const ll MOD = 1e9 + 7;

int T;
int a[U + 1];
ll dp[U + 1][MAX_A + 1];

ll solve() {
    dp[0][0] = 1;
    for (int i = 0; i < U; i++) {
        for (int j = 0; j <= MAX_A; j++) {
            if (dp[i][j] == 0) {
                continue;
            }
            for (int k = j % 2; k <= a[i]; k += 2) {
                (dp[i + 1][(k + j) / 2] += dp[i][j]) %= MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= U; i++) {
        if (a[i] > 0) {
            ans++;
        }
    }
    for (int i = 0; i <= U; i++) {
        (ans += dp[i][1]) %= MOD;
    }

    return ans;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
