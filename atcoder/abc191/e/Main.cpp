/*
[abc191] E - Come Back Quickly
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

const int MAX_N = 2000;
const int MAX_M = 2000;
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
int A[MAX_M], B[MAX_M], C[MAX_M];

void solve() {
    vector<ll> d(N, INF);
    vector<vector<ll>> dd(N);

    Graph g(N);
    REP(j, M) {
        g.add_edge(A[j], B[j], C[j]);
        if (A[j] == B[j]) d[A[j]] = min(d[A[j]], (ll)C[j]);
    }
    REP(i, N) {
        g.dijkstra(i);
        dd[i] = g.dist;
    }
    REP(i, N) {
        ll ans = d[i];
        REP(j, N) {
            if (i == j) continue;
            ans = min(ans, dd[i][j] + dd[j][i]);
        }
        if (ans >= INF) ans = -1;
        cout << ans << endl;
    }
}

int main() {
    cin >> N >> M;
    REP(i, M) cin >> A[i] >> B[i] >> C[i], A[i]--, B[i]--;

    solve();

    return 0;
}
