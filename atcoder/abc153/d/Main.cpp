/*
[abc153] D - Caracal vs Monster
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

ll H;

ll solve() {
    ll ans = 0;
    for (ll p = 1; H > 0; p <<= 1) {
        ans += p;
        H >>= 1;
    }

    return ans;
}

int main() {
    cin >> H;

    cout << solve() << endl;

    return 0;
}
