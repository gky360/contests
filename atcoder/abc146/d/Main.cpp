/*
[abc146] D - Coloring Edges on Tree
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N;
vector<pii> g[MAX_N];
int K;
int ans[MAX_N - 1];

void dfs(int v, int par = -1, int c = K - 1) {
    for (pii p : g[v]) {
        int to = p.first, e = p.second;
        if (to == par) continue;
        (c += 1) %= K;
        ans[e] = c;
        dfs(to, v, c);
    }
}

ll solve() {
    for (int i = 0; i < N; i++) {
        K = max(K, (int)g[i].size());
    }

    dfs(0);

    return K;
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back({b - 1, i});
        g[b - 1].push_back({a - 1, i});
    }

    cout << solve() << endl;
    for (int i = 0; i < N - 1; i++) {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}
