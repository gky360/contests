/*
[tenka1-2018] E - Equilateral
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

const int N = 300;

int H, W;
bool s[N][N];
int cnt[2][N * 4 + 2][N * 4 + 2];

bool is_in(int i, int j) { return 0 <= i && i < H && 0 <= j && j < W; }

ll solve() {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (!s[i][j]) {
                continue;
            }
            for (int d = 1; is_in(i + d, j + d); d++) {
                if (!s[i + d][j + d]) {
                    continue;
                }
                cnt[0][i + j + N][j - i - 2 * d + 2 * N]++;
                cnt[0][i + j + 2 * d + 2 + N][j - i - 2 * d + 2 * N]--;
                cnt[0][i + j + N][j - i + 2 * d + 2 * N]++;
                cnt[0][i + j + 2 * d + 2 + N][j - i + 2 * d + 2 * N]--;
            }
            for (int d = 1; is_in(i - d, j + d); d++) {
                if (!s[i - d][j + d]) {
                    continue;
                }
                cnt[1][i + j + 2 * d + N][j - i + 2 + 2 * N]++;
                cnt[1][i + j + 2 * d + N][j - i + 2 * d + 2 * N]--;
                cnt[1][i + j - 2 * d + N][j - i + 2 + 2 * N]++;
                cnt[1][i + j - 2 * d + N][j - i + 2 * d + 2 * N]--;
            }
        }
    }

    for (int u = 1; u < 4 * N; u++) {
        for (int v = 0; v < 4 * N; v++) {
            cnt[0][u][v] += cnt[0][u - 1][v];
        }
    }
    for (int u = 0; u < 4 * N; u++) {
        for (int v = 1; v < 4 * N; v++) {
            cnt[1][u][v] += cnt[1][u][v - 1];
        }
    }

    ll ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (s[i][j]) {
                int u = i + j;
                int v = j - i;
                ans += cnt[0][u + N][v + 2 * N] + cnt[1][u + N][v + 2 * N];
            }
        }
    }

    return ans;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < W; j++) {
            s[i][j] = (row[j] == '#');
        }
    }

    cout << solve() << endl;

    return 0;
}
