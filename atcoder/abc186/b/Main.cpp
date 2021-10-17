/*
[abc186] B - Blocks on Grid
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

int H, W;
vector<int> a;

ll solve() {
    int m = *min_element(ALL(a));
    int s = accumulate(ALL(a), 0);
    ll ans = s - m * H * W;
    return ans;
}

int main() {
    cin >> H >> W;
    a.resize(H * W);
    REP(i, H) REP(j, W) cin >> a[i * W + j];

    cout << solve() << endl;

    return 0;
}
