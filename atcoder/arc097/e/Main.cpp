/*
[arc097] E - Sorted and Sorted
*/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 2000;
const int INF = 1e8;

int N;
int c[2 * MAX_N], a[2 * MAX_N];
int dp[MAX_N + 1][MAX_N + 1];
int pos[2][MAX_N];
int cost[2][MAX_N][MAX_N + 1];

int solve() {
    for (int i = 0; i < 2 * N; i++) {
        pos[c[i]][a[i]] = i;
    }

    for (int wb = 0; wb < 2; wb++) {
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (pos[wb][i] > pos[wb][j]) {
                    cost[wb][i][N]++;
                }
            }
            for (int j = N - 1; j >= 0; j--) {
                cost[wb][i][j] =
                    cost[wb][i][j + 1] + (pos[wb ^ 1][j] < pos[wb][i]);
            }
        }
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i < N) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost[0][i][j]);
            }
            if (j < N) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + cost[1][j][i]);
            }
        }
    }

    return dp[N][N];
}

int main() {
    cin >> N;
    for (int i = 0; i < 2 * N; i++) {
        char raw_c;
        cin >> raw_c >> a[i];
        c[i] = (raw_c == 'W' ? 0 : 1);
        a[i]--;
    }

    cout << solve() << endl;

    return 0;
}
