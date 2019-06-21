/*
[dp] O - Matching
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

const int MAX_N = 21;
const ll MOD = 1e9 + 7;

int N;
int a[MAX_N][MAX_N];
ll dp[MAX_N + 1][1 << MAX_N];

ll solve() {
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int pat = 0; pat < (1 << N); pat++) {
                if (a[i][j] && (pat & (1 << j)) == 0) {
                    (dp[i + 1][pat | (1 << j)] += dp[i][pat]) %= MOD;
                }
            }
        }
    }

    return dp[N][(1 << N) - 1];
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
