/*
[abc163] A - Circle Pond
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

int R;

double solve() {
    double ans = 2 * R * M_PI;
    return ans;
}

int main() {
    cin >> R;

    cout << fixed << setprecision(20) << solve() << endl;

    return 0;
}
