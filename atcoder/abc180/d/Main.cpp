/*
[abc180] D - Takahashi Unevolved
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

ll X, Y, A, B;

ll solve() {
    ll ans = 0;
    while (X < B && X * (A - 1) < B && X < (Y + A - 1) / A) {
        ans++;
        X *= A;
    }
    ans += (Y - 1 - X) / B;

    return ans;
}

int main() {
    cin >> X >> Y >> A >> B;

    cout << solve() << endl;

    return 0;
}
