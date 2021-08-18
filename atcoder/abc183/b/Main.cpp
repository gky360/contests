/*
[abc183] B - Billiards
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

DD SX, SY, GX, GY;

DD solve() {
    DD ans = (SX * GY + GX * SY) / (SY + GY);
    return ans;
}

int main() {
    cin >> SX >> SY >> GX >> GY;

    cout << fixed << setprecision(10) << solve() << endl;

    return 0;
}
