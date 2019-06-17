/*
[dp] E - Knapsack 2
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
const int MAX_V = 1e3;
const ll INF = 1e18;

int N, W;
int w[MAX_N], v[MAX_N];
ll dp[MAX_N * MAX_V + 1];

ll solve() {
    fill(dp, dp + MAX_N * MAX_V + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = MAX_N * MAX_V; j - v[i] >= 0; j--) {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    for (int j = MAX_N * MAX_V; j >= 0; j--) {
        if (dp[j] <= W) {
            return j;
        }
    }
    return -1;
}

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    cout << solve() << endl;

    return 0;
}
