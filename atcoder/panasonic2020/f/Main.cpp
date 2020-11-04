/*
[panasonic2020] F - Fractal Shortest Path
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int K = 30;

int Q;

bool blocked(ll s1, ll s2, ll t1, ll t2) {
    return s1 == s2 && s1 % 3 == 1 && abs(t2 - t1) >= 2;
}

ll calc(ll x1, ll y1, ll x2, ll y2) {
    ll p = 1;
    ll ans = 0;
    REP(i, K) {
        if (blocked(x1 / p, x2 / p, y1 / p, y2 / p)) {
            ll tmp = min(min(x1 % p, x2 % p) + 1, p - max(x1 % p, x2 % p));
            ans = max(ans, tmp);
        }
        p *= 3;
    }

    return ans;
}

ll solve(ll x1, ll y1, ll x2, ll y2) {
    ll ans = abs(x1 - x2) + abs(y1 - y2) +
             2 * max(calc(x1, y1, x2, y2), calc(y1, x1, y2, x2));
    return ans;
}

int main() {
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        cout << solve(a, b, c, d) << endl;
    }

    return 0;
}
