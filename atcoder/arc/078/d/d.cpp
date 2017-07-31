// AtCoder Regular Contest 078
// D - Fennec VS. Snuke

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100000;

int N;
vector<int> G[MAX_N];
int par[MAX_N];
int depth[MAX_N];
int size[MAX_N];

void dfs(int v) {
    depth[v] = (par[v] < 0) ? 0 : depth[par[v]] + 1;
    size[v] = 1;
    for (int to : G[v]) {
        if (to == par[v]) {
            continue;
        }
        par[to] = v;
        dfs(to);
        size[v] += size[to];
    }
}

int main() {

    int m;
    int a, b;

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    par[0] = -1;
    dfs(0);

    m = N - 1;
    for (int i = 0; i < (depth[N - 1] + 1) / 2 - 1; i++) {
        m = par[m];
    }

    cout << ((N - size[m] > size[m]) ? "Fennec" : "Snuke") << endl;

    return 0;

}



