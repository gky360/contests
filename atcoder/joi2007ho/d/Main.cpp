/*
[joi2007ho] D - 最悪の記者
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 5000;

vector<int> g[MAX_N];

bool visit(int v, vector<int> &order, vector<int> &color) {
    color[v] = 1;
    for (int to : g[v]) {
        if (color[to] == 2) continue;
        if (color[to] == 1 || !visit(to, order, color)) return false;
    }
    order.push_back(v);
    color[v] = 2;
    return true;
}

bool topological_sort(int n, vector<int> &order) {
    vector<int> color(n);
    for (int v = 0; v < n; v++) {
        if (!color[v] && !visit(v, order, color)) return false;
    }
    reverse(ALL(order));
    return true;
}

int N, M;

void solve() {
    vector<int> order;
    topological_sort(N, order);

    bool uniq = true;
    for (int i = 1; i < N; i++) {
        int u = order[i - 1], v = order[i];
        if (find(ALL(g[u]), v) == g[u].end()) {
            uniq = false;
            break;
        }
    }
    for (int v : order) {
        cout << v + 1 << endl;
    }
    cout << (uniq ? 0 : 1) << endl;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
    }

    solve();

    return 0;
}
