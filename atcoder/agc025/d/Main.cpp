/*
[agc025] D - Choosing Points
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 300;

int N;
int D[2];
int color[2 * MAX_N][2 * MAX_N][2];

int calc_color(int x, int y, int d) {
    if (d % 2 == 1) {
        return (x + y) % 2;
    }
    if (d % 4 == 2) {
        return x % 2;
    }
    return calc_color(x / 2, y / 2, d / 4);
}

void solve() {
    int cnt[2][2];
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < 2 * N; i++) {
        for (int j = 0; j < 2 * N; j++) {
            for (int k = 0; k < 2; k++) {
                color[i][j][k] = calc_color(i, j, D[k]);
            }
            int c0 = color[i][j][0];
            int c1 = color[i][j][1];
            cnt[c0][c1]++;
        }
    }

    int ans_c0, ans_c1;
    for (int c0 = 0; c0 < 2; c0++) {
        for (int c1 = 0; c1 < 2; c1++) {
            if (cnt[c0][c1] >= N * N) {
                ans_c0 = c0;
                ans_c1 = c1;
            }
        }
    }

    int cnt_found = 0;
    for (int i = 0; i < 2 * N; i++) {
        for (int j = 0; j < 2 * N; j++) {
            if (color[i][j][0] == ans_c0 && color[i][j][1] == ans_c1) {
                cout << i << " " << j << endl;
                cnt_found++;
                if (cnt_found >= N * N) {
                    return;
                }
            }
        }
    }
}

int main() {
    cin >> N >> D[0] >> D[1];

    solve();

    return 0;
}
