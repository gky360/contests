/*
[abc177] D - Friends
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_M = 2e5;

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

int N, M;
int A[MAX_M], B[MAX_M];

ll solve() {
    UnionFind uf(N);

    REP(i, M) uf.unite(A[i], B[i]);
    int ans = 0;
    REP(i, N) ans = max(ans, uf.size(i));
    return ans;
}

int main() {
    cin >> N >> M;
    REP(i, M) cin >> A[i] >> B[i], A[i]--, B[i]--;

    cout << solve() << endl;

    return 0;
}
