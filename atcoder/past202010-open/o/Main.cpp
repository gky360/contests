/*
[past202010-open] O - 宝箱
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

const int MAX_N = 2e5;
const int MAX_M = 2e5;
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

int N, M;
ll a[MAX_N];
int l[MAX_M], r[MAX_M];
ll c[MAX_M];

ll solve() {
    Graph g(N + 1);

    ll s = 0;
    REP(i, N) {
        s += a[i];
        g.add_edge(i, i + 1, a[i]);
        g.add_edge(i + 1, i, 0);
    }
    REP(i, M) g.add_edge(l[i], r[i] + 1, c[i]);

    g.dijkstra(0);

    ll ans = s - g.dist[N];
    return ans;
}

int main() {
    cin >> N >> M;
    REP(i, N) cin >> a[i];
    REP(i, M) cin >> l[i] >> r[i] >> c[i], l[i]--, r[i]--;

    cout << solve() << endl;

    return 0;
}
