/*
[hhkb2020] E - Lamps
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

const int MOD = 1e9 + 7;
const int MAX_H = 2000;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(ll n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
};

int H, W;
string S[MAX_H + 2];
int cnt[MAX_H + 2][MAX_H + 2][4];
gf p2[MAX_H * MAX_H + 1];

ll solve() {
    REP(i, H) S[i + 1] = '#' + S[i + 1] + '#';
    S[0] = S[H + 1] = string(W + 2, '#');

    int K = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (S[i][j] == '.') K++;
            cnt[i][j][3] = S[i][j] == '.' ? cnt[i][j - 1][3] + 1 : 0;
            cnt[i][j][0] = S[i][j] == '.' ? cnt[i - 1][j][0] + 1 : 0;
        }
    }
    for (int i = H; i > 0; i--) {
        for (int j = W; j > 0; j--) {
            cnt[i][j][1] = S[i][j] == '.' ? cnt[i][j + 1][1] + 1 : 0;
            cnt[i][j][2] = S[i][j] == '.' ? cnt[i + 1][j][2] + 1 : 0;
        }
    }

    p2[0] = 1;
    REP(i, H * W) p2[i + 1] = p2[i] * 2;

    gf ans = p2[K] * K;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (S[i][j] != '.') continue;
            int c = 0;
            REP(d, 4) c += cnt[i][j][d];
            c -= 3;
            ans -= p2[K - c];
        }
    }
    return ans.n;
}

int main() {
    cin >> H >> W;
    REP(i, H) cin >> S[i + 1];

    cout << solve() << endl;

    return 0;
}
