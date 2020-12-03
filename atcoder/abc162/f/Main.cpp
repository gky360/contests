/*
[abc162] F - Select Half
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;
const ll INF = 1e18;

int N;
int A[MAX_N];
ll dp[MAX_N][3];

ll solve() {
    dp[0][0] = -INF;
    dp[0][1] = 0;
    dp[0][2] = A[0];
    dp[1][0] = 0;
    dp[1][1] = max(A[0], A[1]);
    dp[1][2] = -INF;
    for (int i = 2; i < N; i++) REP(j, 3) {
            int pj = j + i % 2;
            dp[i][j] = max(pj < 3 ? dp[i - 1][pj] : -INF, dp[i - 2][j] + A[i]);
        }

    ll ans = dp[N - 1][1];
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
