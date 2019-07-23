/*
[nikkei2019-qual] D - Restore the Tree
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
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
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N, M;
vector<int> g[MAX_N];
bool visited[MAX_N];
int last;
int dep[MAX_N];
int par_dep[MAX_N];
int par[MAX_N];

void dfs(int v) {
    if (visited[v]) {
        return;
    }
    visited[v] = true;

    for (int to : g[v]) {
        dfs(to);
    }
    dep[v] = last--;
}

void solve() {
    last = N;
    for (int i = 0; i < N; i++) {
        dfs(i);
    }

    fill(par, par + N, -1);
    for (int v = 0; v < N; v++) {
        for (int to : g[v]) {
            if (par_dep[to] < dep[v]) {
                par_dep[to] = dep[v];
                par[to] = v;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << par[i] + 1 << endl;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N - 1 + M; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
    }

    solve();

    return 0;
}
