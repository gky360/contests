/*
[past202012-open] H - Conveyor
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

int H, W;
int r, c;
vector<string> s;
int dh[4] = {-1, 0, 1, 0}, dw[4] = {0, 1, 0, -1};

void solve() {
    vector<vector<bool>> visited(H, vector<bool>(W));
    queue<pii> q;
    q.push({r, c});
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        if (visited[a][b]) continue;
        visited[a][b] = true;
        REP(k, 4) {
            int na = a + dh[k], nb = b + dw[k];
            if (0 <= na && na < H && 0 <= nb && nb < W &&
                (s[na][nb] == '.' || (k == 0 && s[na][nb] == 'v') ||
                 (k == 1 && s[na][nb] == '<') || (k == 2 && s[na][nb] == '^') ||
                 (k == 3 && s[na][nb] == '>'))) {
                q.push({na, nb});
            }
        }
    }

    REP(i, H) {
        REP(j, W) {
            if (s[i][j] == '#') {
                cout << '#';
            } else if (visited[i][j]) {
                cout << 'o';
            } else {
                cout << 'x';
            }
        }
        cout << endl;
    }
}

int main() {
    cin >> H >> W;
    cin >> r >> c, r--, c--;
    s.resize(H);
    REP(i, H) cin >> s[i];

    solve();

    return 0;
}
