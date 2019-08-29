/*
[abc120] D - Decayed Bridges
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int MAX_M = 1e5;

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

int N, M;
int A[MAX_M], B[MAX_M];

void solve() {
    UnionFind uf(N);
    ll ans[MAX_M + 1];
    ans[M] = (N - 1LL) * N;
    for (int i = M - 1; i >= 0; i--) {
        if (uf.same(A[i], B[i])) {
            ans[i] = ans[i + 1];
            continue;
        }
        ll as = uf.size(A[i]), bs = uf.size(B[i]);
        ans[i] = ans[i + 1] + (as - 1) * as + (bs - 1) * bs;
        ans[i] -= (as + bs - 1) * (as + bs);
        uf.unite(A[i], B[i]);
    }

    for (int i = 0; i < M; i++) {
        cout << ans[i + 1] / 2 << endl;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    solve();

    return 0;
}
