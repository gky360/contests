/*
[agc033] B - LRUD Game
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_H = 2e5;
const int MAX_W = 2e5;
const int MAX_N = 2e5;

const string ds = "LRUD";
const int dh[4] = {0, 0, -1, 1};
const int dw[4] = {-1, 1, 0, 0};

int H, W, N;
int sr, sc;
string S[2];

bool solve() {
    for (int k = 0; k < 4; k++) {
        int h = sr, w = sc;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2; j++) {
                if (S[j][i] == ds[k ^ j]) {
                    h += dh[k ^ j];
                    w += dw[k ^ j];
                    if (j == 1) {
                        h = max(h, 0);
                        h = min(h, H - 1);
                        w = max(w, 0);
                        w = min(w, W - 1);
                    } else if (h < 0 || H <= h || w < 0 || W <= w) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    cin >> H >> W >> N;
    cin >> sr >> sc;
    sr--;
    sc--;
    cin >> S[0];
    cin >> S[1];

    cout << (solve() ? "YES" : "NO") << endl;

    return 0;
}
