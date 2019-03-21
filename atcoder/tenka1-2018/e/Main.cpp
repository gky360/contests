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
int cnt[2][3 * N + 1][3 * N + 1];

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
                cnt[0][i + d + 1 + N][j - d + 1 + N]++;
                cnt[0][i + 2 * d + N][j + N]--;
                cnt[0][i - d + 1 + N][j + d + 1 + N]++;
                cnt[0][i + N][j + 2 * d + N]--;
            }
            for (int d = 1; is_in(i - d, j + d); d++) {
                if (!s[i - d][j + d]) {
                    continue;
                }
                cnt[1][i + d + N][j + d + N]++;
                cnt[1][i - 1 + N][j + 2 * d + 1 + N]--;
                cnt[1][i - d + N][j - d + N]++;
                cnt[1][i - 2 * d - 1 + N][j + 1 + N]--;
            }
        }
    }

    for (int i = 1; i < 3 * N; i++) {
        for (int j = 1; j < 3 * N; j++) {
            cnt[0][i][j] += cnt[0][i - 1][j - 1];
        }
    }
    for (int i = 3 * N - 2; i >= 0; i--) {
        for (int j = 1; j < 3 * N; j++) {
            cnt[1][i][j] += cnt[1][i + 1][j - 1];
        }
    }

    ll ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (s[i][j]) {
                ans += cnt[0][i + N][j + N] + cnt[1][i + N][j + N];
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
