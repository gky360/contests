// ARC092
// C - 2D Plane 2N Points

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100;
const int MAX_V = MAX_N * 2 + 2;
const int INF = 1e9;

struct edge {
    int to, cap, rev;  // 行き先, 容量, 逆辺番号
};

class Graph {
public:
    void add_edge(int from, int to, int cap);
    int max_flow(int s, int t);

private:
    void bfs(int s);
    int dfs(int v, int t, int f);

private:
    vector<edge> g[MAX_V];
    int level[MAX_V];
    int iter[MAX_V];
};

void Graph::add_edge(int from, int to, int cap) {
    g[from].push_back((edge){to, cap, (int)g[to].size()});
    g[to].push_back((edge){from, 0, (int)g[from].size() - 1});
    return;
}

int Graph::max_flow(int s, int t) {
    int f;
    int flow = 0;

    while (true) {
        bfs(s);
        if (level[t] < 0) {
            break;
        }
        memset(iter, 0, sizeof(iter));
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
    return flow;
}

void Graph::bfs(int s) {
    queue<int> que;
    int v;
    int i;

    memset(level, -1, sizeof(level));
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        v = que.front();
        que.pop();
        for (i = 0; i < (int)g[v].size(); i++) {
            if (g[v][i].cap > 0 && level[g[v][i].to] < 0) {
                level[g[v][i].to] = level[v] + 1;
                que.push(g[v][i].to);
            }
        }
    }
    return;
}

int Graph::dfs(int v, int t, int f) {
    int d;

    if (v == t) {
        return f;
    }
    for (; iter[v] < (int)g[v].size(); iter[v]++) {
        edge &e = g[v][iter[v]];
        if (e.cap > 0 && level[v] < level[e.to]) {
            d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int N;
int a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N];
Graph g;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> c[i] >> d[i];
    }

    int s = 2 * N;
    int t = 2 * N + 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i] < c[j] && b[i] < d[j]) {
                g.add_edge(i, j + N, 1);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        g.add_edge(s, i, 1);
        g.add_edge(i + N, t, 1);
    }

    int ans = g.max_flow(s, t);

    cout << ans << endl;

    return 0;
}
