/*
[hhkb2020] B - Futon
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

const int MAX_H = 100;

int H, W;
string S[MAX_H];

ll solve() {
    ll ans = 0;
    REP(i, H) REP(j, W) {
        if (S[i][j] == '.') {
            if (j + 1 < W && S[i][j + 1] == '.') ans++;
            if (i + 1 < H && S[i + 1][j] == '.') ans++;
        }
    }
    return ans;
}

int main() {
    cin >> H >> W;
    REP(i, H) cin >> S[i];

    cout << solve() << endl;

    return 0;
}
