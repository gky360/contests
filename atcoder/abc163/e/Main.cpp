/*
[abc163] E - Active Infants
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

const int MAX_N = 2000;

int N;
pii ap[MAX_N];
ll dp[MAX_N + 1][MAX_N + 1];

ll solve() {
    sort(ap, ap + N, greater<pii>());
    for (int z = 0; z < N; z++) {
        for (int x = 0; x <= z; x++) {
            int y = z - x;
            dp[x + 1][y] = max(dp[x + 1][y], dp[x][y] + 1LL * ap[z].first *
                                                            (ap[z].second - x));
            dp[x][y + 1] =
                max(dp[x][y + 1], dp[x][y] + 1LL * ap[z].first *
                                                 ((N - 1 - y) - ap[z].second));
        }
    }

    ll ans = 0;
    REP(x, N) {
        int y = N - x;
        ans = max(ans, dp[x][y]);
    }

    return ans;
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> ap[i].first;
        ap[i].second = i;
    }

    cout << solve() << endl;

    return 0;
}
