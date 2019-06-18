/*
[dp] G - Longest Path
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

const int MAX_N = 1e5;

int N, M;
vector<int> g[MAX_N];
int dep[MAX_N];
bool visited[MAX_N];

int dfs(int u) {
    if (visited[u]) {
        return dep[u];
    }
    visited[u] = true;

    dep[u] = 0;
    for (int v : g[u]) {
        dep[u] = max(dep[u], dfs(v) + 1);
    }

    return dep[u];
}

ll solve() {
    for (int i = 0; i < N; i++) {
        dfs(i);
    }

    return *max_element(dep, dep + N);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
    }

    cout << solve() << endl;

    return 0;
}
