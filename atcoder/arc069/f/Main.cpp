/*
[arc069] F - Flags
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2 * 1e4;
const int MAX_V = 6 * MAX_N;
const ll MAX_X = 1e9;
const ll INF = 1e18;

int N;
ll x[2][MAX_N];
pli xn[2 * MAX_N];
vector<vector<int>> g, g_org;

vector<vector<int>> rg, rg_org;  // reversed graph
vector<int> scc[MAX_V];  // scc[k]: set of node ids that belongs to scc k
vector<int> vs;          // node ids in postorder
bool used[MAX_V];
int cmp[MAX_V];  // cmp[v]: topological order of scc to which node v belongs

void dfs(int v) {
    if (used[v]) return;
    used[v] = true;
    for (int to : g[v]) {
        dfs(to);
    }
    vs.push_back(v);
}

void rdfs(int v, int k) {
    if (used[v]) return;
    used[v] = true;
    cmp[v] = k;
    scc[k].push_back(v);
    for (int to : rg[v]) {
        rdfs(to, k);
    }
}

int calc_scc(int V) {
    for (int v = 0; v < V; v++) {
        dfs(v);
    }
    memset(used, 0, sizeof(used));
    reverse(vs.begin(), vs.end());
    int k = 0;
    for (int v : vs) {
        if (!used[v]) rdfs(v, k++);
    }
    return k;
}

void add_edge(int u, int v) {
    g[u].push_back(v);
    rg[v].push_back(u);
}

void add(int s, int a, int b, int k = 0, int l = 0, int r = 2 * N) {
    if (r <= a || b <= l) {
        return;
    }
    if (a <= l && r <= b) {
        add_edge(4 * N - 1 + s, k);
    } else {
        add(s, a, b, k * 2 + 1, l, (l + r) / 2);
        add(s, a, b, k * 2 + 2, (l + r) / 2, r);
    }
}

bool can(ll d) {
    g = g_org;
    rg = rg_org;
    for (int i = 0; i < 6 * N; i++) {
        scc[i].clear();
    }
    vs.clear();
    memset(used, 0, sizeof(used));
    memset(cmp, 0, sizeof(cmp));

    int li = 0, ri = 0;
    for (int i = 0; i < 2 * N; i++) {
        while (li < 2 * N && xn[li].first < xn[i].first - d + 1) li++;
        while (ri < 2 * N && xn[ri].first <= xn[i].first + d - 1) ri++;
        add(i, li, i);
        add(i, i + 1, ri);
    }
    calc_scc(6 * N);

    for (int i = 0; i < 2 * N; i++) {
        if (cmp[4 * N - 1 + i] == cmp[2 * N - 1 + i]) {
            return false;
        }
    }

    return true;
}

ll solve() {
    int n_org = N;
    N = 1;
    while (N < n_org) {
        N <<= 1;
    }
    for (int i = n_org; i < N; i++) {
        x[0][i] = -MAX_X * (i - n_org + 1);
        x[1][i] = MAX_X * (i - n_org + 2);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            xn[2 * i + j].first = x[j][i];
            xn[2 * i + j].second = i;
        }
    }
    sort(xn, xn + 2 * N);

    g.resize(6 * N);
    rg.resize(6 * N);
    for (int i = 0; i < N; i++) {
        int xi = lower_bound(xn, xn + 2 * N, pli(x[0][i], i)) - xn;
        int yi = lower_bound(xn, xn + 2 * N, pli(x[1][i], i)) - xn;
        add_edge(2 * N - 1 + xi, 4 * N - 1 + yi);
        add_edge(2 * N - 1 + yi, 4 * N - 1 + xi);
    }
    for (int i = 1; i < 4 * N - 1; i++) {
        add_edge((i - 1) / 2, i);
    }
    g_org = g;
    rg_org = rg;

    ll ok = 0, ng = MAX_X + 1;
    while (ng - ok > 1) {
        ll m = (ng + ok) / 2;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }

    return ok;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[0][i] >> x[1][i];
    }

    cout << solve() << endl;

    return 0;
}
