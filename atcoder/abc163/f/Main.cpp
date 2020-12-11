/*
[abc163] F - path pass i
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;

int N;
int c[MAX_N];
vector<int> g[MAX_N];
ll cnt[MAX_N], sub[MAX_N];
int s;
ll ans[MAX_N];

int dfs(int v, int par = -1) {
    sub[v] = 1;
    ll buf = cnt[c[v]];
    for (int to : g[v]) {
        if (to == par) continue;
        ll pre = s - cnt[c[v]];
        sub[v] += dfs(to, v);
        ll nxt = s - cnt[c[v]];
        ans[c[v]] -= (nxt - pre) * (nxt - pre - 1) / 2;
    }
    cnt[c[v]] = buf + sub[v];
    s++;
    return sub[v];
}

void solve() {
    REP(i, N) ans[i] = N * (N - 1LL) / 2;
    dfs(0);

    REP(i, N) {
        ll pre = 0, nxt = N - cnt[i];
        ans[i] -= (nxt - pre) * (nxt - pre - 1) / 2;
    }
    REP(i, N) ans[c[i]]++;

    REP(i, N) cout << ans[i] << endl;
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> c[i];
        c[i]--;
    }
    REP(i, N - 1) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    solve();

    return 0;
}
