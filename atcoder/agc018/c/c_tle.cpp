// AtCoder Grand Contest 018
// C - Coins

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100000;
const ll MAX_A = (ll)1e9;
const int MAX_V = MAX_N + 5;
const ll INF = (ll)1e16;

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


int X, Y, Z;
int N;
Graph<ll> g;

int main() {

    ll a, b, c;
    ll ans;

    cin >> X >> Y >> Z;
    N = X + Y + Z;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        g.add_edge(N + 3, i, 1, 0);
        g.add_edge(i, N + 0, 1, MAX_A - a);
        g.add_edge(i, N + 1, 1, MAX_A - b);
        g.add_edge(i, N + 2, 1, MAX_A - c);
    }
    g.add_edge(N + 0, N + 4, X, 0);
    g.add_edge(N + 1, N + 4, Y, 0);
    g.add_edge(N + 2, N + 4, Z, 0);

    ans = MAX_A * N - g.min_cost_flow(N + 3, N + 4, N);
    cout << ans << endl;

    return 0;

}



