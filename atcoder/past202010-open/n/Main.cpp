/*
[past202010-open] N - マス目の穴埋め
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

const int H = 18;
const int W = 6;

string _s[H];
ll dp[H + 2][1 << W][1 << W];

int s(int h, int w) {
    if (h < 0 || H <= h || w < 0 || W <= w) return 0;
    if (_s[h][w] == '?') return -1;
    return _s[h][w] - '0';
}

int cnt(int p0, int p1, int p2, int x) {
    return (((p0 >> x) & 1) + ((p1 >> (x - 1)) & 1) + ((p1 >> x) & 1) +
            ((p1 >> (x + 1)) & 1) + ((p2 >> x) & 1));
}

bool ok(int p0, int p1, int p2, int h) {
    REP(x, W) {
        if (cnt(p0, p1, p2, x) / 3 != ((p1 >> x) & 1)) return false;
        if (s(h - 0, x) == (((p0 >> x) & 1) ^ 1)) return false;
    }
    return true;
}

ll solve() {
    dp[0][0][0] = 1;
    REP(h, H + 1) REP(p2, 1 << W) REP(p1, 1 << W) REP(p0, 1 << W) {
        if (ok(p0, p1, p2, h)) dp[h + 1][p1][p0] += dp[h][p2][p1];
    }

    ll ans = 0;
    REP(p, 1 << W) ans += dp[H + 1][p][0];
    return ans;
}

int main() {
    REP(h, H) cin >> _s[h];

    cout << solve() << endl;

    return 0;
}
