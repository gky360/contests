/*
[dp] A - Frog 1
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

int N;
int h[MAX_N];
int dp[MAX_N];

ll solve() {
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                    dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    return dp[N - 1];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    cout << solve() << endl;

    return 0;
}
