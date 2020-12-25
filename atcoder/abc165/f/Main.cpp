/*
[abc165] F - LIS on Tree
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;
const int INF = 1e9 + 7;

int N;
int a[MAX_N];
vector<int> g[MAX_N];
int ans[MAX_N];

void dfs(vector<int> &path, int v, int par = -1) {
    int idx = lower_bound(ALL(path), a[v]) - path.begin();
    int org = path[idx];
    path[idx] = a[v];
    int len = lower_bound(ALL(path), INF) - path.begin();
    ans[v] = len;
    for (int to : g[v]) {
        if (to == par) continue;
        dfs(path, to, v);
    }
    path[idx] = org;
}

void solve() {
    vector<int> path(N, INF);
    dfs(path, 0);
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    solve();

    return 0;
}
