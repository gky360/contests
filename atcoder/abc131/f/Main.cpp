/*
[abc131] F - Must Be Rectangular!
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int MAX_XY = 1e5 + 1;

int N;
int x[MAX_N], y[MAX_N];
vector<int> g[2 * MAX_XY];
bool visited[2 * MAX_XY];
int cx, cy, ce;

void dfs(int v) {
    if (visited[v]) {
        return;
    }
    visited[v] = true;

    if (v < MAX_XY) {
        cx++;
    } else {
        cy++;
    }
    ce += g[v].size();

    for (int to : g[v]) {
        dfs(to);
    }
}

ll solve() {
    for (int i = 0; i < N; i++) {
        g[x[i]].push_back(y[i] + MAX_XY);
        g[y[i] + MAX_XY].push_back(x[i]);
    }

    ll ans = 0;
    for (int i = 0; i < MAX_XY; i++) {
        cx = cy = ce = 0;
        dfs(i);
        ans += (ll)cx * cy - ce / 2;
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    cout << solve() << endl;

    return 0;
}
