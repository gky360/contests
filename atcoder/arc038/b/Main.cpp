/*
[arc038] B - マス目と駒
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_H = 100;
const int MAX_W = 100;

int H, W;
bool S[MAX_H + 1][MAX_W + 1];
map<pii, int> memo[2];
int dr[3] = {1, 1, 0}, dc[3] = {0, 1, 1};

int dfs(int r, int c, int dep) {
    if (memo[dep & 1][pii(r, c)] != 0) {
        return memo[dep & 1][pii(r, c)];
    }

    int ret = (dep & 1) ? 2 : -2;
    for (int k = 0; k < 3; k++) {
        if (S[r + dr[k]][c + dc[k]]) {
            ret = (dep & 1) ? min(ret, dfs(r + dr[k], c + dc[k], dep + 1))
                            : max(ret, dfs(r + dr[k], c + dc[k], dep + 1));
        }
    }
    if (ret <= -2 || ret >= 2) {
        ret = (dep & 1) ? 1 : -1;
    }
    return (memo[dep & 1][pii(r, c)] = ret);
}

bool solve() { return dfs(0, 0, 0) > 0; }

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++) {
            S[i][j] = (s[j] == '.');
        }
    }

    cout << (solve() ? "First" : "Second") << endl;

    return 0;
}
