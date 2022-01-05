/*
[abc191] C - Digital Graffiti
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

const int MAX_H = 10;

int H, W;
string S[MAX_H];
int dh[4] = {0, 1, 0, 1}, dw[4] = {0, 0, 1, 1};

ll solve() {
    ll ans = 0;
    REP(i, H - 1) REP(j, W - 1) {
        int cnt = 0;
        REP(k, 4) {
            if (S[i + dh[k]][j + dw[k]] == '#') cnt++;
        }
        if (cnt == 1 || cnt == 3) ans++;
    }

    return ans;
}

int main() {
    cin >> H >> W;
    REP(i, H) cin >> S[i];

    cout << solve() << endl;

    return 0;
}
