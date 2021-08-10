/*
[abc182] F - Valid payments
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

const int MAX_N = 50;
const ll INF = 1e18;

int N;
ll X;
ll A[MAX_N];
unordered_map<ll, ll> dp[MAX_N + 1];

ll solve() {
    dp[N][X] = 1;
    for (int i = N - 1; i >= 0; i--) {
        ll p = i + 1 >= N ? INF : A[i + 1] / A[i];
        for (auto [x, c] : dp[i + 1]) {
            ll n = x / A[i];
            ll r = x - n * A[i];
            if (-p < n && n < p) dp[i][r] += c;
            if (r < 0 && -p < n - 1 && n - 1 < p) dp[i][r + A[i]] += c;
            if (r > 0 && -p < n + 1 && n + 1 < p) dp[i][r - A[i]] += c;
        }
    }

    ll ans = dp[0][0];
    return ans;
}

int main() {
    cin >> N >> X;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
