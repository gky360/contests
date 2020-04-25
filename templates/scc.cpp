// scc (Strongly Connected Component)

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_V = 100000;

vector<int> g[MAX_V];
vector<int> rg[MAX_V];   // reversed graph
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

int main() { return 0; }
