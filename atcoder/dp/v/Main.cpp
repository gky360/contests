/*
[dp] V - Subtree
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

const int MAX_N = 1e5;

int N;
ll M;
vector<int> g[MAX_N];
ll dp[MAX_N];
ll ans[MAX_N];

ll dfs1(int v, int p = -1) {
    dp[v] = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        (dp[v] *= dfs1(to, v) + 1) %= M;
    }
    return dp[v];
}

void dfs2(int v, ll res_p = 0, int p = -1) {
    int d = g[v].size();

    vector<ll> ml(d + 1), mr(d + 1);
    ml[0] = mr[d] = 1;
    for (int i = 0; i < d; i++) {
        ll sub = (g[v][i] == p) ? res_p : dp[g[v][i]];
        ml[i + 1] = (ml[i] * (sub + 1)) % M;
    }
    for (int i = d - 1; i >= 0; i--) {
        ll sub = (g[v][i] == p) ? res_p : dp[g[v][i]];
        mr[i] = (mr[i + 1] * (sub + 1)) % M;
    }
    ans[v] = mr[0];

    for (int i = 0; i < d; i++) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        dfs2(to, ml[i] * mr[i + 1] % M, v);
    }
}

void solve() {
    dfs1(0);
    dfs2(0);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    solve();

    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
