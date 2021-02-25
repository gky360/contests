/*
[abc173] C - H and V
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

const int MAX_H = 6;
const int MAX_W = 6;

int H, W, K;
string c[MAX_H];

ll solve() {
    ll ans = 0;
    REP(a, 1 << H) REP(b, 1 << W) {
        int cnt = 0;
        REP(i, H) REP(j, W) {
            if (!((a >> i) & 1) && !((b >> j) & 1) && c[i][j] == '#') cnt++;
        }
        if (cnt == K) ans++;
    }
    return ans;
}

int main() {
    cin >> H >> W >> K;
    REP(i, H) cin >> c[i];

    cout << solve() << endl;

    return 0;
}
