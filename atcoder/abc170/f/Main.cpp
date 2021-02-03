/*
[abc170] F - Pond Skater
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

const int MAX_H = 1e6;
const ll INF = 1e18;

int H, W, K;
int X1, Y1, X2, Y2;
string c[MAX_H];

class Graph {
public:
    vector<ll> dist;
    vector<vector<pli>> g;  // cost, to
    Graph(int n) : dist(n), g(n) {}
    void add_edge(int from, int to, ll cost) {
        g[from].push_back(pli(cost, to));
        return;
    }
    void dijkstra(int s) {
        priority_queue<pli, vector<pli>, greater<pli>> q;
        pli p, e;

        fill(ALL(dist), INF);
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
                ll nd = e.first < 0 ? (dist[p.second] + K - 1) / K * K
                                    : dist[p.second] + e.first;
                if (dist[e.second] > nd) {
                    dist[e.second] = nd;
                    q.push(pli(dist[e.second], e.second));
                }
            }
        }
        return;
    }
};

int dh[4] = {-1, 0, 1, 0}, dw[4] = {0, 1, 0, -1};

ll solve() {
    Graph g(H * W * 4 + 2);
    int S = H * W * 4, T = H * W * 4 + 1;

    REP(i, H) REP(j, W) REP(k, 4) {
        int v = i * W + j;
        g.add_edge(v * 4 + k, v * 4 + (k + 1) % 4, -1);
        int ni = i + dh[k], nj = j + dw[k];
        if (0 <= ni && ni < H && 0 <= nj && nj < W && c[ni][nj] != '@')
            g.add_edge(v * 4 + k, (ni * W + nj) * 4 + k, 1);
    }
    REP(k, 4) g.add_edge(S, (X1 * W + Y1) * 4 + k, 0);
    REP(k, 4) g.add_edge((X2 * W + Y2) * 4 + k, T, 0);

    g.dijkstra(S);

    ll ans = g.dist[T] == INF ? -1 : (g.dist[T] + K - 1) / K;
    return ans;
}

int main() {
    cin >> H >> W >> K;
    cin >> X1 >> Y1 >> X2 >> Y2;
    X1--, Y1--, X2--, Y2--;
    REP(i, H) cin >> c[i];

    cout << solve() << endl;

    return 0;
}
