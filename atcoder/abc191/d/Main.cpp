/*
[abc191] D - Circle Lattice Points
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

const ll D = 10000;

DD x, y, r;

ll solve() {
    ll X = round(x * D), Y = round(y * D), R = round(r * D);
    ll ans = 0;
    for (ll t = ceil(y - r); t <= floor(y + r); t++) {
        ll sec[2];
        REP(i, 2) {
            ll ok = i == 0 ? ceil(x) : floor(x);
            ll ng = i == 0 ? floor(x - r - 1) : ceil(x + r + 1);
            while (abs(ok - ng) > 1) {
                ll m = (ok + ng) / 2;
                if ((m * D - X) * (m * D - X) + (t * D - Y) * (t * D - Y) <=
                    R * R) {
                    ok = m;
                } else {
                    ng = m;
                }
            }
            sec[i] = ok;
        }
        if (sec[0] <= sec[1]) ans += sec[1] - sec[0] + 1;
    }

    return ans;
}

int main() {
    cin >> x >> y >> r;

    cout << solve() << endl;

    return 0;
}
