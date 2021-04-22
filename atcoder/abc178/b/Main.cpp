/*
[abc178] B - Product Max
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

ll a, b, c, d;

ll solve() {
    vector<ll> v = {a * c, a * d, b * c, b * d};
    sort(ALL(v));

    ll ans = *v.rbegin();
    return ans;
}

int main() {
    cin >> a >> b >> c >> d;

    cout << solve() << endl;

    return 0;
}
