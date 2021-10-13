/*
[abc185] C - Duodecim Ferra
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

ll L;

ll solve() {
    ll ans = 1;
    REP(i, 11) {
        ans *= L - 1 - i;
        ans /= i + 1;
    }
    return ans;
}

int main() {
    cin >> L;

    cout << solve() << endl;

    return 0;
}
