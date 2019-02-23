/*
[code-festival-2018-quala] D - 通勤
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

const int MAX_N = 100000;
const ll MOD = 1e9 + 7;

ll D, T, F;
int N;
ll x[MAX_N + 1];
ll dp[MAX_N + 1];
ll pow2[MAX_N + 1];
int ub[MAX_N + 1];

void prepare() {
    pow2[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    int j = 0;
    for (int i = 0; i <= N; i++) {
        while (j <= N && x[j] <= x[i] + F - T) {
            j++;
        }
        ub[i] = j;
    }
}

ll solve() {
    dp[0] = 1;
    ll s = 0;
    int l = 0, r = 0;
    for (int n = 1; n <= N; n++) {
        for (; l <= N && x[l] < x[n] - F; l++) {
            (s += MOD - dp[l] * pow2[ub[l] - l - 1] % MOD) %= MOD;
        }
        for (; r <= N + 1 && x[r] < x[n] + T - F; r++) {
            (s += dp[r] * pow2[ub[r] - r - 1]) %= MOD;
        }
        dp[n] = s;
    }

    ll ans = 0;
    for (int n = N; n >= 0 && D - x[n] <= F; n--) {
        (ans += dp[n] * pow2[ub[n] - n - 1]) %= MOD;
    }

    return ans;
}

int main() {
    cin >> D >> F >> T >> N;
    x[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> x[i];
    }

    prepare();

    cout << solve() << endl;

    return 0;
}
