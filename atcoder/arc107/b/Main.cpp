/*
[arc107] B - Quadruple
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

int N, K;

ll calc(int x) { return min(N, x - 1) - max(1, x - N) + 1; }

ll solve() {
    ll ans = 0;
    for (int ab = 2; ab <= 2 * N; ab++) {
        int cd = ab - K;
        if (2 <= cd && cd <= 2 * N) ans += 1LL * calc(ab) * calc(cd);
    }
    return ans;
}

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
