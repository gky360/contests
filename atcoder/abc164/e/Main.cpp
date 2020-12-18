/*
[abc164] E - Two Currencies
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

const int MAX_N = 50;
const int MAX_M = 100;
const int MAX_A = 50;
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

int N, M, S;
int U[MAX_M], V[MAX_M], A[MAX_M], B[MAX_M];
int C[MAX_N], D[MAX_N];

void solve() {
    int P = N * MAX_A;
    Graph g(N * P);
    REP(i, N) {
        REP(j, P) {
            if (j + C[i] < P) g.add_edge(i * P + j, i * P + j + C[i], D[i]);
        }
    }
    REP(i, M) {
        REP(j, P) {
            if (j + A[i] < P) {
                g.add_edge(U[i] * P + j + A[i], V[i] * P + j, B[i]);
                g.add_edge(V[i] * P + j + A[i], U[i] * P + j, B[i]);
            }
        }
    }

    g.dijkstra(0 * P + min(P - 1, S));

    for (int i = 1; i < N; i++) {
        ll ans = INF;
        REP(j, P) { ans = min(ans, g.dist[i * P + j]); }
        cout << ans << endl;
    }
}

int main() {
    cin >> N >> M >> S;
    REP(i, M) {
        cin >> U[i] >> V[i] >> A[i] >> B[i];
        U[i]--, V[i]--;
    }
    REP(i, N) { cin >> C[i] >> D[i]; }

    solve();

    return 0;
}
