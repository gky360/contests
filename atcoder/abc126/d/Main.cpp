/*
[abc126] D - Even Relation
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
vector<pli> g[MAX_N];
bool ans[MAX_N];

void dfs(int v, ll h, int par = -1) {
    ans[v] = h % 2 == 0;
    for (auto &e : g[v]) {
        ll w = e.first;
        int to = e.second;
        if (to == par) {
            continue;
        }
        dfs(to, h + w, v);
    }
}

void solve() {
    dfs(0, 0);

    for (int i = 0; i < N; i++) {
        cout << (ans[i] ? '1' : '0') << endl;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    solve();

    return 0;
}
