// bipartite matching

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_V = 100000;

vector<int> g[MAX_V];
int match[MAX_V];
bool used[MAX_V];

bool dfs(int v) {
    used[v] = true;
    for (int u : g[v]) {
        int w = match[u];
        if (w < 0 || (!used[w] && dfs(w))) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching(int V) {
    int cnt = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < V; v++) {
        if (match[v] < 0) {
            memset(used, 0, sizeof(used));
            if (dfs(v)) {
                cnt++;
            }
        }
    }

    return cnt;
}

int main() { return 0; }
