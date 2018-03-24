// AtCoder Regular Contest 080
// D - Grid Coloring

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_H = 100;
const int MAX_W = 100;
const int MAX_N = MAX_H * MAX_W;

int H, W;
int N;
int a[MAX_N + 1];
int ans[MAX_H][MAX_N];

int main() {

    int color, h, w;

    cin >> H >> W;
    cin >> N;
    a[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    color = 0;
    for (int idx = 0; idx < H * W; idx++) {
        if (a[color] <= idx) {
            color++;
        }
        h = idx / W;
        w = ((h % 2 == 0) ? (idx % W) : (W - 1 - idx % W));
        ans[h][w] = color;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << ans[i][j];
            cout << (j == W - 1 ? '\n' : ' ');
        }
    }

    return 0;

}



