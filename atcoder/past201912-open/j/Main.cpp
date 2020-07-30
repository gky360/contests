/*
[past201912-open] J - 地ならし / Leveling
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_H = 50;
const int MAX_W = 50;
int dh[4] = {-1, 0, 1, 0};
int dw[4] = {0, 1, 0, -1};

const int MAX_V = MAX_H * MAX_W;
const ll INF = 1e18;

class Graph {
public:
    ll dist[MAX_V];
    vector<pli> g[MAX_V];  // cost, to
    void add_edge(int from, int to, ll cost) {
        g[from].push_back(pli(cost, to));
        return;
    }
    void dijkstra(int s) {
        priority_queue<pli, vector<pli>, greater<pli>> q;
        pli p, e;

        fill(dist, dist + MAX_V, INF);
        dist[s] = 0;
        q.push(pli(dist[s], s));
        while (!q.empty()) {
            p = q.top();
            q.pop();
            if (dist[p.second] < p.first) {
                continue;
            }
            for (int i = 0; i < (int)g[p.second].size(); i++) {
                e = g[p.second][i];
                if (dist[e.second] > dist[p.second] + e.first) {
                    dist[e.second] = dist[p.second] + e.first;
                    q.push(pli(dist[e.second], e.second));
                }
            }
        }
        return;
    }
};

int H, W;
int A[MAX_H][MAX_W];

int get_id(int h, int w) { return h * W + w; }

ll calc(int h, int w) {
    Graph g;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < 4; k++) {
                if (0 <= i + dh[k] && i + dh[k] < H && 0 <= j + dw[k] &&
                    j + dw[k] < W) {
                    g.add_edge(get_id(i, j), get_id(i + dh[k], j + dw[k]),
                               A[i + dh[k]][j + dw[k]]);
                }
            }
        }
    }
    g.dijkstra(get_id(h, w));
    return g.dist[get_id(H - 1, 0)] + g.dist[get_id(H - 1, W - 1)] +
           g.dist[get_id(0, W - 1)] + A[h][w];
}

ll solve() {
    ll ans = INF;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans = min(ans, calc(i, j));
        }
    }

    return ans;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}
