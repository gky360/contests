/*
[abc165] B - 1%
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

ll X;

ll solve() {
    ll ans = 0;
    for (ll a = 100; a < X; a += a / 100) {
        ans++;
    }

    return ans;
}

int main() {
    cin >> X;

    cout << solve() << endl;

    return 0;
}
