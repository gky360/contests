/*
[yahoo-procon2019-final] B - Bonsai Grafting
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N[2];
vector<int> g[2][MAX_N];
int dia[2];
vector<pii> cds[2][MAX_N];
int d[2][MAX_N];

pii farest(int k, int s) {
    queue<pii> q;
    bool visited[MAX_N];
    memset(visited, 0, sizeof(visited));

    pii ret = {-1, -1};
    q.push({0, s});
    while (!q.empty()) {
        pii p = q.front();
        int d = p.first;
        int v = p.second;
        q.pop();
        if (visited[v]) {
            continue;
        }
        visited[v] = true;
        ret = p;

        for (int to : g[k][v]) {
            q.push({d + 1, to});
        }
    }

    return ret;
}

int dfs1(int k, int v, int par = -1) {
    cds[k][v].push_back({0, -1});
    for (int to : g[k][v]) {
        if (to == par) {
            continue;
        }
        cds[k][v].push_back({dfs1(k, to, v) + 1, to});
    }
    sort(cds[k][v].begin(), cds[k][v].end(), greater<pii>());
    return cds[k][v][0].first;
}

void dfs2(int k, int v, int par = -1, int pd = 0) {
    d[k][v] = max(cds[k][v][0].first, pd);
    for (int to : g[k][v]) {
        if (to == par) {
            continue;
        }
        if (cds[k][v][0].second == to) {
            dfs2(k, to, v, max(pd, cds[k][v][1].first) + 1);
        } else {
            dfs2(k, to, v, max(pd, cds[k][v][0].first) + 1);
        }
    }
}

ll solve() {
    for (int k = 0; k < 2; k++) {
        pii f0 = farest(k, 0);
        pii f1 = farest(k, f0.second);
        dia[k] = f1.first;

        dfs1(k, 0);
        dfs2(k, 0);
    }
    int c = max(dia[0], dia[1]);

    sort(d[1], d[1] + N[1]);
    ll s[MAX_N + 1];
    s[0] = 0;
    for (int i = 0; i < N[1]; i++) {
        s[i + 1] = s[i] + d[1][i];
    }

    ll ans = 0;
    for (int i = 0; i < N[0]; i++) {
        int x = upper_bound(d[1], d[1] + N[1], c - d[0][i] - 1) - d[1];
        ans +=
            1LL * x * c + (N[1] - x + 0LL) * (d[0][i] + 1) + (s[N[1]] - s[x]);
    }

    return ans;
}

int main() {
    for (int k = 0; k < 2; k++) {
        cin >> N[k];
        for (int i = 0; i < N[k] - 1; i++) {
            int p, q;
            cin >> p >> q;
            g[k][p - 1].push_back(q - 1);
            g[k][q - 1].push_back(p - 1);
        }
    }

    cout << solve() << endl;

    return 0;
}
