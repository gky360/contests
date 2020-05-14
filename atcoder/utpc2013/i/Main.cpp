/*
[utpc2013] I - 支配と友好
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int INF = 2e9;

int N;
int a[MAX_N];
vector<int> g[MAX_N];
set<int> s;
int ans[MAX_N];

void update(int v, int t) {
    if (abs(a[v] - t) < abs(a[v] - ans[v])) ans[v] = t;
    if (abs(a[v] - t) == abs(a[v] - ans[v])) ans[v] = min(ans[v], t);
}

void dfs(int v, bool order) {
    auto iter = s.lower_bound(a[v]);
    if (iter != s.end()) {
        if (ans[v] == -1) ans[v] = *iter;
        update(v, *iter);
    }
    if (iter != s.begin()) {
        --iter;
        update(v, *iter);
    }

    if (order) {
        for (int to : g[v]) dfs(to, order);
    } else {
        for (int i = g[v].size() - 1; i >= 0; i--) {
            dfs(g[v][i], order);
        }
    }

    s.insert(a[v]);
}

void solve() {
    bool is_root[MAX_N];
    memset(is_root, true, sizeof(is_root));

    for (int i = 0; i < N; i++) {
        for (int to : g[i]) {
            is_root[to] = false;
        }
    }
    int root = find(is_root, is_root + N, true) - is_root;

    memset(ans, -1, sizeof(ans));
    dfs(root, true);
    s.clear();
    dfs(root, false);

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
        int s, t;
        cin >> s >> t;
        g[s].push_back(t);
    }

    solve();

    return 0;
}
