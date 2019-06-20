/*
[dp] L - Deque
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

int N;
ll a[MAX_N];
ll dp[MAX_N + 1][MAX_N + 1];

ll solve() {
    for (int i = 1; i <= N; i++) {
        for (int l = 0; l + i <= N; l++) {
            int r = l + i;
            if ((N - i) % 2 == 0) {
                dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r - 1]);
            } else {
                dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r - 1]);
            }
        }
    }

    return dp[0][N];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
