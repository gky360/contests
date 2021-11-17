/*
[abc188] F - +1-1x2
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

ll X, Y;
unordered_map<ll, ll> f;

ll calc(ll y) {
    if (f.count(y) > 0) return f[y];
    ll ret = abs(X - y);
    if ((y & 1) && y != 1) {
        ret = min(ret, min(calc((y + 1) / 2) + 2, calc((y - 1) / 2) + 2));
    } else if (!(y & 1)) {
        ret = min(ret, calc(y / 2) + 1);
    }
    return f[y] = ret;
}

ll solve() {
    ll ans = calc(Y);
    return ans;
}

int main() {
    cin >> X >> Y;

    cout << solve() << endl;

    return 0;
}
