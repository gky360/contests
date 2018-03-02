// ARC084
// D - Small Multiple

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_K = 100000;
const int MAX_V = MAX_K;
const int INF = 1e9;

class Graph {
public:
    void add_edge(int from, int to, int cost);  // 有向辺を追加
    void dijkstra(int s);
    int dist[MAX_V];
    int V;  // <- 初期化忘れずに
private:
    vector<pii> g[MAX_V];  // cost, to
};

void Graph::add_edge(int from, int to, int cost) {
    g[from].push_back(pii(cost, to));
    return;
}

void Graph::dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii> > q;
    pii p, e;

    fill(dist, dist + V, INF);
    dist[s] = 0;
    q.push(pii(dist[s], s));
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
                q.push(pii(dist[e.second], e.second));
            }
        }
    }
    return;
}

int K;
Graph g;

int main() {
    cin >> K;

    g.V = K;
    for (int i = 0; i < K; i++) {
        g.add_edge(i, (i + 1) % K, 1);
        g.add_edge(i, (i * 10) % K, 0);
    }
    g.dijkstra(1);

    cout << g.dist[0] + 1 << endl;

    return 0;
}
