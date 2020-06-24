/*
[nikkei2019-2-qual] D - Shortest Path on a Line
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
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
int L[MAX_M], R[MAX_M], C[MAX_M];

ll solve() {
    Graph g(N);
    for (int i = 0; i < N - 1; i++) {
        g.add_edge(i + 1, i, 0);
    }
    for (int j = 0; j < M; j++) {
        g.add_edge(L[j], R[j], C[j]);
    }

    g.dijkstra(0);

    ll ans = g.dist[N - 1];
    if (ans >= INF) {
        ans = -1;
    }
    return ans;
}

int main() {
    cin >> N >> M;
    for (int j = 0; j < M; j++) {
        cin >> L[j] >> R[j] >> C[j];
        L[j]--, R[j]--;
    }

    cout << solve() << endl;

    return 0;
}
