// min_cost_flow.cpp
// 最小費用流を求める
// グラフは隣接リスト型

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define MAX_V 100
#define INF 100000000
using namespace std;


template <typename T>
struct edge{
    int to, cap;
    T cost;
    int rev;
};

template <typename T>
class Graph{
public:
    void add_edge(int from, int to, int cap, T cost);
    T min_cost_flow(int s, int t, int f);
private:
    vector<edge<T>> g[MAX_V];
    T h[MAX_V];
    T dist[MAX_V];
    int pre_v[MAX_V], pre_e[MAX_V];
};

template <typename T>
void Graph<T>::add_edge(int from, int to, int cap, T cost) {
    g[from].push_back((edge<T>){to, cap, cost, (int)g[to].size()});
    g[to].push_back((edge<T>){from, 0, -cost, (int)g[from].size() - 1});
    return;
}

template <typename T>
T Graph<T>::min_cost_flow(int s, int t, int f) {
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> que;
    // first: tmp min distance, second: vertex index
    pair<T, int> p;
    int d;
    T cost = 0;

    memset(h, 0, sizeof(h));
    while (f > 0) {
        fill(dist, dist + MAX_V, INF);
        dist[s] = 0;
        que.push(pair<T, int>(0, s));
        while (!que.empty()) {
            p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first) {
                continue;
            }
            for (int i = 0; i < (int)g[v].size(); i++) {
                edge<T> e = g[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    pre_v[e.to] = v;
                    pre_e[e.to] = i;
                    que.push(pair<T, int>(dist[e.to], e.to));
                }
            }
        }
        if (dist[t] >= INF) {
            return -1;
        }

        for (int v = 0; v < MAX_V; v++) {
            h[v] = min(INF, h[v] + dist[v]);
        }

        d = f;
        for (int v = t; v != s; v = pre_v[v]) {
            d = min(d, g[pre_v[v]][pre_e[v]].cap);
        }
        f -= d;
        cost += h[t] * d;
        for (int v = t; v != s; v = pre_v[v]) {
            edge<T> &e = g[pre_v[v]][pre_e[v]];
            e.cap -= d;
            g[v][e.rev].cap += d;
        }
    }
    return cost;
}


int main(){
    return 0;
}

