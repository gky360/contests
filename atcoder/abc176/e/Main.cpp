/*
[abc176] E - Bomber
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

const int MAX_H = 3e5;
const int MAX_W = 3e5;
const int MAX_M = 3e5;

int H, W, M;
int h[MAX_M], w[MAX_M];
int ch[MAX_H], cw[MAX_W];

ll solve() {
    int max_h = 0, max_w = 0;
    REP(i, M) {
        if (max_h < ++ch[h[i]]) max_h = ch[h[i]];
        if (max_w < ++cw[w[i]]) max_w = cw[w[i]];
    }

    int mch = 0, mcw = 0;
    REP(i, H) if (ch[i] == max_h) mch++;
    REP(j, W) if (cw[j] == max_w) mcw++;

    ll cnt = 1LL * mch * mcw;
    REP(i, M) if (ch[h[i]] == max_h && cw[w[i]] == max_w) cnt--;

    ll ans = cnt > 0 ? max_h + max_w : (max_h + max_w - 1);
    return ans;
}

int main() {
    cin >> H >> W >> M;
    REP(i, M) cin >> h[i] >> w[i], h[i]--, w[i]--;

    cout << solve() << endl;

    return 0;
}
