/*
[past202012-open] E - Stamp
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
const int MAX_W = 10;

int H, W;
vector<string> S, T;

void rotate() {
    int h = T.size(), w = T[0].size();
    vector<string> t(w, string(h, '.'));
    REP(i, h) REP(j, w) t[j][h - i - 1] = T[i][j];
    T = t;
}

bool check(int p, int q) {
    REP(i, T.size()) REP(j, T[0].size()) {
        int a = i + p, b = j + q;
        if (T[i][j] == '.') continue;
        if (a < 0 || H <= a || b < 0 || W <= b || S[a][b] == '#') return false;
    }
    return true;
}

bool solve() {
    REP(k, 4) {
        for (int p = -MAX_H + 1; p < MAX_H - 1; p++) {
            for (int q = -MAX_W + 1; q < MAX_W - 1; q++) {
                if (check(p, q)) return true;
            }
        }
        rotate();
    }

    return false;
}

int main() {
    cin >> H >> W;
    S.resize(H), T.resize(H);
    REP(i, H) cin >> S[i];
    REP(i, H) cin >> T[i];

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
