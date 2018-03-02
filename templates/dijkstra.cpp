// dijkstra.cpp
// ダイクストラ法(有向グラフ用)
// グラフは隣接リスト型

#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
#define MAX_V 1000
#define INF 100000000
using namespace std;

typedef pair<int, int> pii;

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

int main() { return 0; }
