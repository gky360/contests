/*
[abc157] D - Friend Suggestions
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100000;
const int MAX_M = 100000;
const int MAX_K = 100000;

int N, M, K;
int A[MAX_M], B[MAX_M];
int C[MAX_K], D[MAX_K];
int d[MAX_N];

class UnionFind {
public:
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : (data[x] = root(data[x])); }
    int size(int x) { return -data[root(x)]; }
};

void solve() {
    UnionFind uf(N);

    for (int i = 0; i < M; i++) {
        uf.unite(A[i], B[i]);
        d[A[i]]++, d[B[i]]++;
    }
    for (int i = 0; i < K; i++) {
        if (uf.same(C[i], D[i])) {
            d[C[i]]++, d[D[i]]++;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << uf.size(i) - d[i] - 1 << ' ';
    }
    cout << endl;
    return;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }
    for (int i = 0; i < K; i++) {
        cin >> C[i] >> D[i];
        C[i]--, D[i]--;
    }

    solve();

    return 0;
}
