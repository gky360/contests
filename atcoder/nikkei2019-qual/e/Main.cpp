/*
[nikkei2019-qual] E - Weights on Vertices and Edges
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
const int MAX_M = 1e5;

class UnionFind {
public:
    vector<ll> data;
    UnionFind(int size) : data(size, -1) {}
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) {
            return false;
        }
        if (data[y] < data[x]) {
            swap(x, y);
        }
        data[x] += data[y];
        data[y] = x;

        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : (data[x] = root(data[x])); }
    ll size(int x) { return -data[root(x)]; }
};

struct Edge {
    int u, v;
    ll w;
    bool operator<(Edge e) { return w < e.w; }
};

int N, M;
ll X[MAX_N];
Edge es[MAX_M];
vector<pii> g[MAX_N];
bool is_cand[MAX_M];
bool used[MAX_M];

ll solve() {
    sort(es, es + M);

    UnionFind uf(N);
    for (int i = 0; i < N; i++) {
        uf.data[i] = -X[i];
    }
    for (int i = 0; i < M; i++) {
        g[es[i].u].push_back({es[i].v, i});
        g[es[i].v].push_back({es[i].u, i});

        uf.unite(es[i].u, es[i].v);
        if (uf.size(es[i].v) >= es[i].w) {
            is_cand[i] = true;
        }
    }

    int ans = M;
    for (int i = M - 1; i >= 0; i--) {
        if (used[i] || !is_cand[i]) {
            continue;
        }

        queue<int> q;
        q.push(es[i].u);
        q.push(es[i].v);
        used[i] = true;
        ans--;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (pii p : g[v]) {
                int to = p.first, m = p.second;
                if (used[m] || es[m].w > es[i].w) {
                    continue;
                }
                used[m] = true;
                ans--;
                q.push(to);
            }
        }
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> es[i].u >> es[i].v >> es[i].w;
        es[i].u--;
        es[i].v--;
    }

    cout << solve() << endl;

    return 0;
}
