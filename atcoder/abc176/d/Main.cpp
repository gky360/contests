/*
[abc176] D - Wizard in Maze
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

const int MAX_H = 1e3;
const int MAX_W = 1e3;
const int MAX_N = MAX_H * MAX_W;
const int INF = 1e9;

int H, W;
int CH, CW, DH, DW;
string S[MAX_H];
int dh[4] = {-1, 0, 1, 0};
int dw[4] = {0, 1, 0, -1};
int ddh[20] = {-2, -2, -2, -2, -2, -1, 0,  1,  2, 2,
               2,  2,  2,  1,  0,  -1, -1, -1, 1, 1};
int ddw[20] = {-2, -1, 0,  1,  2,  2,  2,  2, 2, 1,
               0,  -1, -2, -2, -2, -2, -1, 1, 1, -1};

bool is_in(int h, int w) { return 0 <= h && h < H && 0 <= w && w < W; }

ll solve() {
    vector<vector<pii>> g(H * W);
    vector<int> dist(H * W, INF);

    REP(i, H) REP(j, W) {
        if (S[i][j] != '.') continue;
        REP(k, 4) {
            int h = i + dh[k], w = j + dw[k];
            if (is_in(h, w) && S[h][w] == '.') {
                g[i * W + j].push_back(pii(0, h * W + w));
            }
        }
        REP(k, 20) {
            int h = i + ddh[k], w = j + ddw[k];
            if (is_in(h, w) && S[h][w] == '.') {
                g[i * W + j].push_back(pii(1, h * W + w));
            }
        }
    }

    dist[CH * W + CW] = 0;
    deque<int> q;
    q.push_back(CH * W + CW);

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto [c, to] : g[v]) {
            int d = dist[v] + c;
            if (d < dist[to]) {
                dist[to] = d;
                if (c == 0) {
                    q.push_front(to);
                } else {
                    q.push_back(to);
                }
            }
        }
    }

    ll ans = dist[DH * W + DW];
    return ans == INF ? -1 : ans;
}

int main() {
    cin >> H >> W;
    cin >> CH >> CW;
    cin >> DH >> DW;
    CH--, CW--, DH--, DW--;
    REP(i, H) cin >> S[i];

    cout << solve() << endl;

    return 0;
}
