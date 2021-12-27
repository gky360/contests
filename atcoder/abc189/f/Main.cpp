/*
[abc189] F - Sugoroku2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef complex<double> pdd;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N, M, K;
set<int> A;
pdd dp[MAX_N + 1], s[MAX_N + 1];

void solve() {
    int cnt = 0;
    REP(i, N) {
        cnt = A.count(i) ? cnt + 1 : 0;
        if (cnt >= M) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        dp[i] = A.count(i)
                    ? pdd(0, 1)
                    : ((s[i + 1] - s[min(i + 1 + M, N)]) * (1.0 / M) + 1.0);
        s[i] = s[i + 1] + dp[i];
    }

    double ans = dp[0].real() / (1.0 - dp[0].imag());
    cout << fixed << setprecision(4) << ans << endl;
}

int main() {
    cin >> N >> M >> K;
    REP(i, K) {
        int a;
        cin >> a;
        A.insert(a);
    }

    solve();

    return 0;
}
