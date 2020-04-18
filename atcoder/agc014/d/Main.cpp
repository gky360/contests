/*
[agc014] D - Black and White Tree
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MAX_V = MAX_N;

int N;
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

bool solve() { return (bipartite_matching(N) * 2 < N); }

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    cout << (solve() ? "First" : "Second") << endl;

    return 0;
}
