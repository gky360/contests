// TDPC
// R - グラフ

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 300;

int N;
int V;
vector<int> gg[MAX_N + 1], rg[MAX_N + 1], g[MAX_N + 1], scc[MAX_N + 1], vs;
int cmp[MAX_N + 1], w[MAX_N + 1], dp[MAX_N + 1][MAX_N + 1];
bool used[MAX_N + 1], can[MAX_N + 1][MAX_N + 1];

void dfs(int v, vector<int> a_g[]) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    for (int u : a_g[v]) {
        dfs(u, a_g);
    }
    vs.push_back(v);
}

void rdfs(int v, int k) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    cmp[v] = k;
    scc[k].push_back(v);
    for (int u : rg[v]) {
        rdfs(u, k);
    }
}

int calc_scc() {
    memset(used, 0, sizeof(used));
    vs.clear();
    for (int v = 0; v < N; v++) {
        dfs(v, gg);
    }
    memset(used, 0, sizeof(used));
    reverse(vs.begin(), vs.end());
    int k = 0;
    for (int v : vs) {
        if (!used[v]) {
            rdfs(v, k);
            k++;
        }
    }
    return k + 1;
}

void build_graph() {
    for (int i = 0; i < V; i++) {
        w[i] = scc[i].size();
        for (int j = 0; j < w[i]; j++) {
            for (int& v : gg[scc[i][j]]) {
                g[i].push_back(cmp[v]);
            }
        }
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }
    for (int i = 0; i < V - 1; i++) {
        g[V - 1].push_back(i);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int e;
            cin >> e;
            if (e == 1) {
                gg[i].push_back(j);
                rg[j].push_back(i);
            }
        }
    }

    V = calc_scc();
    build_graph();

    memset(used, 0, sizeof(used));
    vs.clear();
    for (int i = 0; i < V; i++) {
        dfs(i, g);
    }
    reverse(vs.begin(), vs.end());

    memset(can, 0, sizeof(can));
    for (int i = 0; i < V; i++) {
        for (int j : g[i]) {
            can[i][j] = true;
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                can[i][j] = can[i][j] || (can[i][k] && can[k][j]);
            }
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < i; j++) {
            int u = vs[i], v = vs[j];
            dp[u][v] = max(dp[u][v], w[u] + w[v]);
            for (int k = i + 1; k < V; k++) {
                int nu = vs[k];
                if (can[u][nu]) {
                    dp[nu][v] = max(dp[nu][v], dp[u][v] + w[nu]);
                }
                if (can[v][nu]) {
                    dp[nu][u] = max(dp[nu][u], dp[u][v] + w[nu]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}
