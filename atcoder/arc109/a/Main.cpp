/*
[arc109] A - Hands
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

int a, b, x, y;

ll solve() {
    int d = abs(2 * a - 2 * b - 1);
    ll ans = d / 2 * min(y, 2 * x) + d % 2 * x;
    return ans;
}

int main() {
    cin >> a >> b >> x >> y;

    cout << solve() << endl;

    return 0;
}
