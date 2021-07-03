/*
[arc106] B - Values
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
const int MAX_M = 2e5;

int N, M;
ll a[MAX_N], b[MAX_N];
int c[MAX_M], d[MAX_M];
vector<int> g[MAX_N];
int visited[MAX_N];
ll sa[MAX_N], sb[MAX_N];

void dfs(int v, int n) {
    if (visited[v] >= 0) return;
    visited[v] = n;
    for (int to : g[v]) dfs(to, n);
}

ll solve() {
    REP(i, M) {
        g[c[i]].push_back(d[i]);
        g[d[i]].push_back(c[i]);
    }
    memset(visited, -1, sizeof(visited));
    REP(i, N) dfs(i, i);

    REP(i, N) {
        sa[visited[i]] += a[i];
        sb[visited[i]] += b[i];
    }
    REP(i, N) {
        if (sa[i] != sb[i]) return false;
    }
    return true;
}

int main() {
    cin >> N >> M;
    REP(i, N) cin >> a[i];
    REP(i, N) cin >> b[i];
    REP(i, M) cin >> c[i] >> d[i], c[i]--, d[i]--;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
