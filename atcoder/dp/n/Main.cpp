/*
[dp] N - Slimes
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

const int MAX_N = 400;
const ll INF = 1e18;

int N;
int a[MAX_N];
ll s[MAX_N + 1];
ll dp[MAX_N + 1][MAX_N + 1];

ll solve() {
    s[0] = 0;
    for (int i = 0; i < N; i++) {
        s[i + 1] = s[i] + a[i];
    }

    for (int i = 2; i <= N; i++) {
        for (int l = 0; l + i <= N; l++) {
            int r = l + i;
            dp[l][r] = INF;
            for (int m = l + 1; m < r; m++) {
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m][r] + s[r] - s[l]);
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
