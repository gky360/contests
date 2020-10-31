/*
[panasonic2020] B - Bishop
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

ll H, W;

ll solve() {
    if (H == 1 || W == 1) {
        return 1;
    }
    ll ans = (H * W + 1LL) / 2LL;
    return ans;
}

int main() {
    cin >> H >> W;

    cout << solve() << endl;

    return 0;
}
