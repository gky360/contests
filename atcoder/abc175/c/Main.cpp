/*
[abc175] C - Walking Takahashi
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

ll X, K, D;

ll solve() {
    X = abs(X);
    ll c = X / D;
    if (c % 2 != K % 2) c++;
    c = min(c, K);
    ll ans = abs(X - D * c);
    return ans;
}

int main() {
    cin >> X >> K >> D;

    cout << solve() << endl;

    return 0;
}
