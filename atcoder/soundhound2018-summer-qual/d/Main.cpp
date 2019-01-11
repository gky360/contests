/*
[soundhound2018-summer-qual] D - Saving Snuuk
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;
const ll X = 1e15;
const int MAX_V = MAX_N;
const ll INF = 1e18;

class Graph {
public:
    ll dist[MAX_V];
    vector<pli> g[MAX_V];  // cost, to
    void add_edge(int from, int to, ll cost);
    void dijkstra(int s);
};

void Graph::add_edge(int from, int to, ll cost) {
    g[from].push_back(pli(cost, to));
    return;
}

void Graph::dijkstra(int s) {
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

int N, M, S, T;
Graph g[2];

void solve() {
    g[0].dijkstra(S);
    g[1].dijkstra(T);

    vector<ll> ans(N + 1);
    ans[N] = -1;
    for (int i = N - 1; i >= 0; i--) {
        ans[i] = max(ans[i + 1], X - (g[0].dist[i] + g[1].dist[i]));
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    cin >> N >> M >> S >> T;
    S--;
    T--;
    for (int i = 0; i < M; i++) {
        int u, v, c[2];
        cin >> u >> v >> c[0] >> c[1];
        u--;
        v--;
        for (int p = 0; p < 2; p++) {
            g[p].add_edge(u, v, c[p]);
            g[p].add_edge(v, u, c[p]);
        }
    }

    solve();

    return 0;
}
