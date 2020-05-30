/*
[abc142] E - Get Everything
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 12;
const int MAX_M = 1e3;
const int INF = 1e9;

int N, M;
int A[MAX_M], B[MAX_M];
int C[MAX_M][MAX_N];
int dp[1 << MAX_N];

ll solve() {
    int cp[MAX_M];
    for (int i = 0; i < M; i++) {
        cp[i] = 0;
        for (int j = 0; j < B[i]; j++) {
            cp[i] = cp[i] | (1 << C[i][j]);
        }
    }

    fill(dp, dp + (1 << N), INF);
    dp[0] = 0;
    for (int i = 0; i < M; i++) {
        for (int pat = 0; pat < (1 << N); pat++) {
            dp[pat | cp[i]] = min(dp[pat | cp[i]], dp[pat] + A[i]);
        }
    }

    int ans = dp[(1 << N) - 1] >= INF ? -1 : dp[(1 << N) - 1];

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        for (int j = 0; j < B[i]; j++) {
            cin >> C[i][j];
            C[i][j]--;
        }
    }

    cout << solve() << endl;

    return 0;
}
