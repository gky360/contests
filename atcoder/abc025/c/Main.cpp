/*
[abc025] C - 双子と○×ゲーム
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int INF = 1e9;

int b[3][3], c[3][3];
int s;
map<int, int> memo;

int calc(int m) {
    bool ox[3][3];

    for (int i = 0, p = 1; i < 9; i++, p *= 3) {
        ox[i / 3][i % 3] = (m / p) % 3 == 1;
    }

    int score = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (ox[i][j] == ox[i + 1][j]) {
                score += b[i][j];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (ox[i][j] == ox[i][j + 1]) {
                score += c[i][j];
            }
        }
    }
    return score;
}

int dfs(int m, int d) {
    if (memo.count(m)) {
        return memo[m];
    }

    int ret = d % 2 ? INF : -INF;
    for (int i = 0, p = 1; i < 9; i++, p *= 3) {
        if ((m / p) % 3 == 0) {
            int s = dfs(m + p * (d % 2 + 1), d + 1);
            ret = d % 2 ? min(ret, s) : max(ret, s);
        }
    }
    if (ret >= INF || ret <= -INF) {
        ret = calc(m);
    }
    return (memo[m] = ret);
}

void solve() {
    int score_o = dfs(0, 0);
    int score_x = s - score_o;

    cout << score_o << endl;
    cout << score_x << endl;
}

int main() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> b[i][j];
            s += b[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> c[i][j];
            s += c[i][j];
        }
    }

    solve();

    return 0;
}
