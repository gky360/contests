/*
[abc184] E - Third Avenue
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

const int MAX_H = 2000;
const int MAX_W = 2000;
const int AZ = 26;
const ll INF = 1e18;

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
string a[MAX_H];
int S, G;
int dh[4] = {-1, 0, 1, 0}, dw[4] = {0, 1, 0, -1};

ll solve() {
    Graph g(H * W + AZ);

    REP(n, H * W) {
        int i = n / W, j = n % W;
        if (a[i][j] == '#') continue;
        if (a[i][j] == 'S') S = n;
        if (a[i][j] == 'G') G = n;
        REP(k, 4) {
            int p = i + dh[k], q = j + dw[k];
            if (0 <= p && p < H && 0 <= q && q < W) g.add_edge(n, p * W + q, 1);
        }
        if ('a' <= a[i][j] && a[i][j] <= 'z') {
            int nn = H * W + (a[i][j] - 'a');
            g.add_edge(n, nn, 1);
            g.add_edge(nn, n, 0);
        }
    }

    g.dijkstra(S);

    ll ans = g.dist[G] == INF ? -1 : g.dist[G];
    return ans;
}

int main() {
    cin >> H >> W;
    REP(i, H) cin >> a[i];

    cout << solve() << endl;

    return 0;
}
