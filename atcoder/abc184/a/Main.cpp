/*
[abc184] A - Determinant
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

int a, b, c, d;

ll solve() {
    ll ans = a * d - b * c;
    return ans;
}

int main() {
    cin >> a >> b;
    cin >> c >> d;

    cout << solve() << endl;

    return 0;
}
