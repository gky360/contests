/*
[arc109] B - log
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

const ll RN = 2e9;

ll n;

bool can(ll m) { return m * (m + 1) / 2 <= n + 1; }

ll solve() {
    ll ok = 0, ng = RN;
    while (ng - ok > 1) {
        ll m = (ng + ok) / 2;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }

    ll ans = n + 1 - ok;
    return ans;
}

int main() {
    cin >> n;

    cout << solve() << endl;

    return 0;
}
