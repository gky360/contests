/*
[nikkei2019-2-final] C - Largest N
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_H = 3000;
const int MAX_W = 3000;

int H, W, K;
bool m[MAX_H][MAX_W];
int u[MAX_H][MAX_W], d[MAX_H][MAX_W];

int check(int h, int w) {
    set<int> s;
    int ret = 0;
    for (int i = h, j = w; i < H && j < W; i++, j++) {
        if (!m[i][j]) {
            s.clear();
        } else {
            s.insert(j);
            set<int>::iterator iter;
            while ((iter = s.lower_bound(j + 1 - u[i][j])) != s.end()) {
                int x = *iter;
                if (d[i - j + x][x] + x >= j + 1) {
                    ret = max(ret, j - x + 1);
                    break;
                }
                s.erase(iter);
            }
        }
    }
    return ret;
}

ll solve() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            u[i][j] = m[i][j] ? (i > 0 ? u[i - 1][j] : 0) + 1 : 0;
        }
    }
    for (int i = H - 1; i >= 0; i--) {
        for (int j = 0; j < W; j++) {
            d[i][j] = m[i][j] ? (i + 1 < H ? d[i + 1][j] : 0) + 1 : 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < H; i++) {
        ans = max(ans, check(i, 0));
    }
    for (int j = 1; j < W; j++) {
        ans = max(ans, check(0, j));
    }

    return ans;
}

int main() {
    cin >> H >> W >> K;
    memset(m, true, sizeof(m));
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        m[a - 1][b - 1] = false;
    }

    cout << solve() << endl;

    return 0;
}
