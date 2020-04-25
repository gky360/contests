/*
[tdpc] R - グラフ
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 300;
const int MAX_V = MAX_N + 1;

vector<int> g[MAX_V], rg[MAX_V], scc[MAX_V], vs;
bool used[MAX_V];
int cmp[MAX_V];

void dfs(int v) {
    if (used[v]) return;
    used[v] = true;
    for (int to : g[v]) {
        dfs(to);
    }
    vs.push_back(v);
}

void rdfs(int v, int k) {
    if (used[v]) return;
    used[v] = true;
    cmp[v] = k;
    scc[k].push_back(v);
    for (int to : rg[v]) {
        rdfs(to, k);
    }
}

int calc_scc(int V) {
    for (int v = 0; v < V; v++) {
        dfs(v);
    }
    memset(used, 0, sizeof(used));
    reverse(vs.begin(), vs.end());
    int k = 0;
    for (int v : vs) {
        if (!used[v]) rdfs(v, k++);
    }
    return k;
}

int sz(int v) { return scc[v].size(); }

int N;
bool gx[MAX_V][MAX_V];
int dp[MAX_V][MAX_V];

ll solve() {
    for (int v = 1; v <= N; v++) {
        g[0].push_back(v);
        rg[v].push_back(0);
    }
    calc_scc(N + 1);

    for (int a = 0; a <= N; a++) {
        for (int b : g[a]) {
            int u = cmp[a], v = cmp[b];
            if (u != v) gx[u][v] = true;
        }
    }

    for (int k = 0; k <= N; k++) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                gx[i][j] = gx[i][j] || (gx[i][k] && gx[k][j]);
            }
        }
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = max(dp[i][j], sz(i) + sz(j));
            for (int k = i + 1; k <= N; k++) {
                if (gx[i][k]) dp[k][j] = max(dp[k][j], dp[i][j] + sz(k));
                if (gx[j][k]) dp[k][i] = max(dp[k][i], dp[i][j] + sz(k));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    ans--;

    return ans;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int e;
            cin >> e;
            if (e) {
                g[i].push_back(j);
                rg[j].push_back(i);
            }
        }
    }

    cout << solve() << endl;

    return 0;
}
