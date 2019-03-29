/*
[dwacon5th-prelims] D - Square Rotation
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

const int MAX_N = 1e5;
const int MAX_D = 1000;

int N, D;
int x[MAX_N], y[MAX_N];
int c[MAX_D][MAX_D];
int s[3][MAX_D * 2 + 1][MAX_D * 2 + 1];

bool can(int q) {
    for (int a = 0; a < D; a++) {
        for (int b = 0; b < D; b++) {
            bool is_ok =
                (s[2][a + q + 1][b + q + 1] - s[2][a + q + 1][b] -
                     s[2][a][b + q + 1] + s[2][a][b] ==
                 0) &&
                (s[1][a + q + 1][b + D] - s[1][a + q + 1][b + q + 1] -
                     s[1][a][b + D] + s[1][a][b + q + 1] ==
                 0) &&
                (s[1][a + D][b + q + 1] - s[1][a + D][b] -
                     s[1][a + q + 1][b + q + 1] + s[1][a + q + 1][b] ==
                 0) &&
                (s[0][a + D][b + D] - s[0][a + D][b + q + 1] -
                     s[0][a + q + 1][b + D] + s[0][a + q + 1][b + q + 1] ==
                 0);
            if (is_ok) {
                return true;
            }
        }
    }

    return false;
}

ll solve() {
    int p = 0;
    for (int i = 0; i < N; i++) {
        c[x[i] % D][y[i] % D]++;
    }
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < D; j++) {
            while ((p + 1) * (p + 1) < c[i][j]) {
                p++;
            }
        }
    }

    int thresh[3] = {p * p, p * (p + 1), (p + 1) * (p + 1)};
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < D; j++) {
                if (c[i][j] > thresh[k]) {
                    s[k][1 + i][1 + j]++;
                    s[k][1 + i + D][1 + j]++;
                    s[k][1 + i][1 + j + D]++;
                    s[k][1 + i + D][1 + j + D]++;
                }
            }
        }
    }

    for (int k = 0; k < 3; k++) {
        for (int i = 1; i <= 2 * D; i++) {
            for (int j = 0; j <= 2 * D; j++) {
                s[k][i + 1][j] += s[k][i][j];
            }
        }
        for (int i = 0; i <= 2 * D; i++) {
            for (int j = 1; j <= 2 * D; j++) {
                s[k][i][j + 1] += s[k][i][j];
            }
        }
    }

    int ng = -1, ok = D - 1;
    while (ok - ng > 1) {
        int m = (ok + ng) / 2;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }

    ll ans = p * D + ok;
    return ans;
}

int main() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    cout << solve() << endl;

    return 0;
}
