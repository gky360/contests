/*
[past202012-open] M - Shipping Sticks
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

int N;
ll L;
ll A[MAX_N + 1];

bool can(ll m) {
    vector<int> dp(N + 2);
    dp[0] = 1, dp[1] = -1;
    int l = 0, r = 0;
    for (int i = 0; i <= N; i++) {
        if (i - 1 >= 0) dp[i] += dp[i - 1];
        if (dp[i] == 0) continue;
        while (l <= N && A[l] - A[i] < m) l++;
        while (r <= N && A[r] - A[i] <= L) r++;
        dp[l]++, dp[r]--;
    }

    return dp[N] > 0;
}

ll solve() {
    REP(i, N) A[i + 1] += A[i];

    ll ok = 0, ng = L + 1;
    while (ng - ok > 1) {
        ll m = (ng + ok) / 2;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }

    ll ans = ok;
    return ans;
}

int main() {
    cin >> N;
    cin >> L;
    REP(i, N) cin >> A[i + 1];

    cout << solve() << endl;

    return 0;
}
