/*
[agc041] C - Domino Quality
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1000;

int N;
char ans[MAX_N][MAX_N];
char k3[8][8] = {
    ".aa",
    "b..",
    "b..",
};
char k4[8][8] = {
    "abcc",
    "abdd",
    "eegh",
    "ffgh",
};
char k5[8][8] = {
    "aabbe",  //
    "c.iie",  //
    "cj..f",  //
    "dj..f",  //
    "dgghh",  //
};
char k6[8][8] = {
    ".aacee",  //
    "b..c.f",  //
    "b..ddf",  //
    "ggi.kk",  //
    "h.il..",  //
    "hjjl..",  //
};
char k7[8][8] = {
    ".aa.cce",  //
    "b..d..e",  //
    "b..d..j",  //
    ".ff.hhj",  //
    "g..i..k",  //
    "g..i..k",  //
    "llmmnn.",  //
};

void put(int x, int y, int k) {
    auto kk = k3;
    if (k == 4) {
        kk = k4;
    }
    if (k == 5) {
        kk = k5;
    }
    if (k == 6) {
        kk = k6;
    }
    if (k == 7) {
        kk = k7;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            ans[x + i][y + j] = kk[i][j];
        }
    }
}

bool solve() {
    memset(ans, '.', sizeof(ans));
    if (N <= 2) {
        return false;
    }
    if (N == 3) {
        put(0, 0, 3);
        return true;
    }

    int p = (N - 4) / 4, m = N % 4 + 4;
    for (int i = 0; i < p; i++) {
        put(4 * i, 4 * i, 4);
    }
    put(4 * p, 4 * p, m);
    return true;
}

int main() {
    cin >> N;

    if (solve()) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
