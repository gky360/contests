/*
[sumitrust2019] F - Interval Running
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const ll INF = 1e18;

ll T1, T2;
ll A1, A2;
ll B1, B2;

ll solve() {
    ll p = T1 * (A1 - B1), q = T2 * (A2 - B2);
    if (p > 0) {
        p *= -1;
        q *= -1;
    }
    if (p + q == 0) {
        return INF;
    }
    if (p + q < 0) {
        return 0;
    }
    ll c = -p / (p + q);
    ll ans = (-p) % (p + q) == 0 ? 2 * c : 2 * c + 1;
    return ans;
}

int main() {
    cin >> T1 >> T2;
    cin >> A1 >> A2;
    cin >> B1 >> B2;

    ll ans = solve();
    if (ans >= INF) {
        cout << "infinity" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
