/*
[abc151] D - Maze Master
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_H = 20;
const int MAX_W = 20;
const int INF = 1e9;

int dh[4] = {-1, 0, 1, 0};
int dw[4] = {0, 1, 0, -1};

int H, W;
string S[MAX_H];

int idx(int h, int w) { return h * W + w; }

ll solve() {
    int d[MAX_H * MAX_W][MAX_H * MAX_W];
    for (int i = 0; i < H * W; i++) {
        for (int j = 0; j < H * W; j++) {
            d[i][j] = INF;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') continue;
            for (int k = 0; k < 4; k++) {
                int h = i + dh[k], w = j + dw[k];
                if (0 <= h && h < H && 0 <= w && w < W && S[h][w] == '.') {
                    d[idx(i, j)][idx(h, w)] = d[idx(h, w)][idx(i, j)] = 1;
                }
            }
        }
    }

    for (int k = 0; k < H * W; k++) {
        for (int i = 0; i < H * W; i++) {
            for (int j = 0; j < H * W; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < H * W; i++) {
        for (int j = 0; j < H * W; j++) {
            if (i != j && d[i][j] < INF) {
                ans = max(ans, d[i][j]);
            }
        }
    }

    return ans;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    cout << solve() << endl;

    return 0;
}
