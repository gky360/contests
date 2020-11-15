/*
[abc160] B - Golden Coins
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

int X;

ll solve() {
    ll ans = X / 500 * 1000 + (X - X / 500 * 500) / 5 * 5;
    return ans;
}

int main() {
    cin >> X;

    cout << solve() << endl;

    return 0;
}
