/*
[abc117] D - XXOR
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
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int MAX_D = 40;

template <typename T>
void chmax(T &x, T v) {
    x = max(x, v);
}

int N;
ll K;
ll A[MAX_N];
int cnt[MAX_D];
ll dp[MAX_D + 1][2];

ll solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MAX_D; j++) {
            if ((A[i] >> j) & 1LL) {
                cnt[j]++;
            }
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[MAX_D][0] = 0;
    for (int j = MAX_D - 1; j >= 0; j--) {
        for (int smaller = 0; smaller < 2; smaller++) {
            if (dp[j + 1][smaller] == -1) {
                continue;
            }
            for (int i = 0; i <= (smaller ? 1 : ((K >> j) & 1LL)); i++) {
                chmax(dp[j][smaller || i < ((K >> j) & 1LL)],
                      dp[j + 1][smaller] +
                          (1LL << j) * (i ? (N - cnt[j]) : cnt[j]));
            }
        }
    }
    ll ans = max(dp[0][0], dp[0][1]);

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
