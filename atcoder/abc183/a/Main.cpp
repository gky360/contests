/*
[abc183] A - ReLU
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

int x;

ll solve() {
    ll ans = max(0, x);
    return ans;
}

int main() {
    cin >> x;

    cout << solve() << endl;

    return 0;
}
