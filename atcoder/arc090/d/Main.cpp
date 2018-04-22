// ARC090
// D - People on a Line

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;

int N, M;
vector<pii> g[MAX_N];
int x[MAX_N];
bool visited[MAX_N];

bool dfs(int v, int y = 0) {
    if (visited[v]) {
        return x[v] == y;
    }
    x[v] = y;
    visited[v] = true;

    bool res = true;
    for (pii &e : g[v]) {
        res = res && dfs(e.second, x[v] + e.first);
    }
    return res;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;
        g[l].push_back(pii(d, r));
        g[r].push_back(pii(-d, l));
    }

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) {
        if (!visited[i] && !dfs(i)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
