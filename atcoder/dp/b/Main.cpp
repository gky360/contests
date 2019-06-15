/*
[dp] B - Frog 2
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
const int INF = 1e9;

int N, K;
int h[MAX_N];
int dp[MAX_N];

ll solve() {
    dp[0] = 0;

    for (int i = 1; i < N; i++) {
        dp[i] = INF;
        for (int k = 1; i - k >= 0 && k <= K; k++) {
            dp[i] = min(dp[i], dp[i - k] + abs(h[i] - h[i - k]));
        }
    }

    return dp[N - 1];
}
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    cout << solve() << endl;

    return 0;
}
