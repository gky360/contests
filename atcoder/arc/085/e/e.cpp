// ARC085
// E - MUL

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100;
const int MAX_V = MAX_N + 2;
const ll INF = 1e18;

template <typename T>
struct edge {
    int to;
    T cap;
    int rev;
};

template <typename T>
class Graph {
public:
    void add_edge(int from, int to, T cap);
    T max_flow(int s, int t);

private:
    void bfs(int s);
    T dfs(int v, int t, T f);
    vector<edge<T>> g[MAX_V];
    int level[MAX_V];
    int iter[MAX_V];
};

template <typename T>
void Graph<T>::add_edge(int from, int to, T cap) {
    g[from].push_back((edge<T>){to, cap, (int)g[to].size()});
    g[to].push_back((edge<T>){from, 0, (int)g[from].size() - 1});
    return;
}

template <typename T>
T Graph<T>::max_flow(int s, int t) {
    T f;
    T flow = 0;

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

template <typename T>
void Graph<T>::bfs(int s) {
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

template <typename T>
T Graph<T>::dfs(int v, int t, T f) {
    T d;

    if (v == t) {
        return f;
    }
    for (; iter[v] < (int)g[v].size(); iter[v]++) {
        edge<T> &e = g[v][iter[v]];
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
Graph<ll> g;

int main() {
    cin >> N;

    int S = 0;
    int T = N + 1;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        if (a < 0) {
            g.add_edge(S, i, -a);
        } else {
            ans += a;
            g.add_edge(i, T, a);
        }
        for (int j = 2 * i; j <= N; j += i) {
            g.add_edge(i, j, INF);
        }
    }

    ans -= g.max_flow(S, T);
    cout << ans << endl;

    return 0;
}
