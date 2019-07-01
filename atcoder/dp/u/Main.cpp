/*
[dp] U - Grouping
*/

#include <algorithm>
#include <bitset>
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

const int MAX_N = 16;
const ll INF = 1LL << 60;

int N;
int a[MAX_N][MAX_N];
ll dp[1 << MAX_N], s[1 << MAX_N];

ll solve() {
    int full = (1 << N) - 1;

    fill(dp, dp + full + 1, -INF);

    for (int b = 0; b <= full; b++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((b >> i) & (b >> j) & 1) {
                    s[b] += a[i][j];
                }
            }
        }
    }

    dp[0] = 0;
    for (int b = 0; b <= full; b++) {
        int nb = full ^ b;
        for (int sub = nb; sub >= 0; sub--) {
            sub &= nb;
            dp[b | sub] = max(dp[b | sub], dp[b] + s[sub]);
        }
    }

    return dp[full] / 2;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}
