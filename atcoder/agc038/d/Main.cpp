/*
[agc038] D - Unique Path
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MAX_Q = 1e5;

class UnionFind {
public:
    vector<int> data;
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
    int size(int x) { return -data[root(x)]; }
};

ll N, M;
int Q;
int A[MAX_Q], B[MAX_Q], C[MAX_Q];
vector<int> g[MAX_N];
bool visited[MAX_N];

void dfs(int v) {
    if (visited[v]) {
        return;
    }
    visited[v] = true;

    for (int to : g[v]) {
        dfs(to);
    }
}

bool solve() {
    if (M == N - 1) {
        return find(C, C + Q, 1) - C == Q;
    }

    UnionFind uf(N);
    for (int q = 0; q < Q; q++) {
        if (C[q] == 0) {
            g[A[q]].push_back(B[q]);
            g[B[q]].push_back(A[q]);
            uf.unite(A[q], B[q]);
        }
    }

    for (int q = 0; q < Q; q++) {
        if (C[q] == 1 && uf.same(A[q], B[q])) {
            return false;
        }
    }

    ll k = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            k++;
        }
        dfs(i);
    }

    return M <= N + k * (k - 3) / 2;
}

int main() {
    cin >> N >> M >> Q;
    for (int q = 0; q < Q; q++) {
        cin >> A[q] >> B[q] >> C[q];
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
