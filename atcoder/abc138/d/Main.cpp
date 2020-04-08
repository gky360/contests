/*
[abc138] D - Ki
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;
const int MAX_Q = 2e5;

int N, Q;
vector<int> g[MAX_N];
int p[MAX_Q], x[MAX_Q];
int ans[MAX_N];

void dfs(int v, int par = -1) {
    if (par >= 0) {
        ans[v] += ans[par];
    }
    for (int to : g[v]) {
        if (to == par) {
            continue;
        }
        dfs(to, v);
    }
}

void solve() {
    for (int i = 0; i < Q; i++) {
        ans[p[i]] += x[i];
    }
    dfs(0);

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < Q; i++) {
        cin >> p[i] >> x[i];
        p[i]--;
    }

    solve();

    return 0;
}
