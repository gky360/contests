/*
[dp] X - Tower
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
typedef tuple<int, int, ll> piil;

const int MAX_N = 1e3;
const int MAX_W = 2 * 1e4;

int N;
piil wsv[MAX_N];
ll dp[MAX_N + 1][MAX_W + 1];

ll solve() {
    sort(wsv, wsv + N, [](auto &a, auto &b) {
        return (get<0>(a) + get<1>(a) == get<0>(b) + get<1>(b))
                   ? get<0>(a) < get<0>(b)
                   : get<0>(a) + get<1>(a) < get<0>(b) + get<1>(b);
    });

    for (int i = 1; i <= N; i++) {
        int w = get<0>(wsv[i - 1]), s = get<1>(wsv[i - 1]);
        ll v = get<2>(wsv[i - 1]);
        for (int j = 0; j <= MAX_W; j++) {
            dp[i][j] = dp[i - 1][j];
            if (0 <= j - w && j - w <= s) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
            }
        }
    }

    ll ans = *max_element(dp[N], dp[N] + MAX_W + 1);
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> get<0>(wsv[i]) >> get<1>(wsv[i]) >> get<2>(wsv[i]);
    }

    cout << solve() << endl;

    return 0;
}
