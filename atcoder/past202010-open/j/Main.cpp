/*
[past202010-open] J - ワープ
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

const int MAX_N = 1e5;
const int MAX_M = 1e5;
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
int X[3];
string S;
int A[MAX_M], B[MAX_M], C[MAX_M];

ll solve() {
    Graph g(N + 6);
    REP(i, M) {
        g.add_edge(A[i], B[i], C[i]);
        g.add_edge(B[i], A[i], C[i]);
    }
    REP(i, N) {
        int t = S[i] - 'A';
        g.add_edge(i, N + t, X[t]);
        g.add_edge(i, N + (t + 2) % 3 + 3, X[(t + 2) % 3]);
        g.add_edge(N + t + 3, i, 0);
        g.add_edge(N + (t + 2) % 3, i, 0);
    }

    g.dijkstra(0);

    ll ans = g.dist[N - 1];
    return ans;
}

int main() {
    cin >> N >> M;
    cin >> X[0] >> X[2] >> X[1];
    cin >> S;
    REP(i, M) cin >> A[i] >> B[i] >> C[i], A[i]--, B[i]--;

    cout << solve() << endl;

    return 0;
}
