/*
[soundhound2018-summer-qual] E - + Graph
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
const ll INF = 1e18;

struct edge {
    int to;
    ll cost;
};

int N, M;
vector<edge> g[MAX_N];
bool visited[MAX_N];
ll cands[2][MAX_N];  // cands[0][i]- t, cands[1][i] + t
ll t_min, t_max;

bool dfs(int v) {
    if (visited[v]) {
        return true;
    }
    visited[v] = true;

    bool ret = true;
    for (edge& e : g[v]) {
        for (int i = 0; i < 2; i++) {
            if (cands[i ^ 1][v] == -INF) {
                continue;
            }
            if (cands[i][e.to] != -INF &&
                cands[i][e.to] != e.cost - cands[i ^ 1][v]) {
                return false;
            }
            cands[i][e.to] = e.cost - cands[i ^ 1][v];
        }
        ret = ret && dfs(e.to);
    }

    return ret;
}

ll solve() {
    fill(cands[0], cands[0] + N, -INF);
    fill(cands[1], cands[1] + N, -INF);
    cands[1][0] = 0;
    if (!dfs(0)) {
        return 0;
    }

    t_min = 0;
    t_max = INF;
    for (int i = 0; i < N; i++) {
        if (cands[0][i] != -INF && cands[1][i] != -INF) {
            if ((cands[0][i] - cands[1][i]) % 2 != 0) {
                return 0;
            }
            int t_new = (cands[0][i] - cands[1][i]) / 2;
            if (t_new < t_min || t_new > t_max) {
                return 0;
            }
            t_min = t_max = t_new;
        } else if (cands[0][i] != -INF) {
            t_max = min(t_max, cands[0][i] - 1);
        } else if (cands[1][i] != -INF) {
            t_min = max(t_min, -cands[1][i] + 1);
        }
    }

    return max(0LL, t_max - t_min + 1);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        ll s;
        cin >> u >> v >> s;
        u--;
        v--;
        g[u].push_back((edge){v, s});
        g[v].push_back((edge){u, s});
    }

    cout << solve() << endl;

    return 0;
}
