/*
[arc109] D - L
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

int T;
ll ax, ay, bx, by, cx, cy;

ll solve() {
    ll p = ax + bx + cx, q = ay + by + cy;
    p = (p > 0 ? p - p / 3 : p + (2 - p) / 3) - 1;
    q = (q > 0 ? q - q / 3 : q + (2 - q) / 3) - 1;
    if (p == 0 && q == 0) return 0;
    if (p == 1 && q == 1) return 1;
    return max({p, -p, q, -q}) + (p == q);

    ll ans = 0;
    return ans;
}

int main() {
    cin >> T;
    REP(t, T) {
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        cout << solve() << endl;
    }

    return 0;
}
