/*
[dp] I - Coins
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
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

const int MAX_N = 2999;

int N;
double p[MAX_N];
double dp[2][MAX_N + 1];

double solve() {
    dp[0][0] = 1.0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i % 2][j] = 0;
        }
        for (int j = 0; j < i; j++) {
            dp[i % 2][j] += dp[(i - 1) % 2][j] * (1 - p[i - 1]);
        }
        for (int j = 1; j <= i; j++) {
            dp[i % 2][j] += dp[(i - 1) % 2][j - 1] * p[i - 1];
        }
    }

    double ans = 0;
    for (int j = N; j > N - j; j--) {
        ans += dp[N % 2][j];
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    cout << setprecision(10) << solve() << endl;

    return 0;
}
