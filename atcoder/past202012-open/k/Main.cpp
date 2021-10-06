/*
[past202012-open] K - Pitching
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

const int N = 4;
const double INF = 1e6;

string S[N];
int dh[5] = {0, -1, 0, 1, 0}, dw[5] = {0, 0, 1, 0, -1};

double dp[1 << (N * N)];

int k(int h, int w) { return 1 << (h * N + w); }

double solve() {
    for (int mask = 1; mask < 1 << (N * N); mask++) {
        dp[mask] = INF;
        REP(i, N) REP(j, N) {
            int miss = 0;
            double sum = 0;
            REP(d, 5) {
                int a = i + dh[d], b = j + dw[d];
                if (a < 0 || N <= a || b < 0 || N <= b) {
                    miss++;
                } else if (mask & k(a, b)) {
                    sum += dp[mask ^ k(a, b)];
                } else {
                    miss++;
                }
            }
            if (miss < 5) dp[mask] = min(dp[mask], (5.0 + sum) / (5.0 - miss));
        }
    }

    int mask = 0;
    REP(i, N) REP(j, N) {
        if (S[i][j] == '#') mask |= k(i, j);
    }

    double ans = dp[mask];
    return ans;
}

int main() {
    REP(i, N) cin >> S[i];

    cout << fixed << setprecision(10) << solve() << endl;

    return 0;
}
