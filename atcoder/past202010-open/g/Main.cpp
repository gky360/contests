/*
[past202010-open] G - 村整備
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

const int MAX_N = 10;

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
string S[MAX_N];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

bool can(int p, int q) {
    UnionFind uf(N * M);

    if (S[p][q] == '.') return false;
    S[p][q] = '.';
    int cnt = 0;
    REP(i, N) REP(j, M) {
        if (S[i][j] == '#') continue;
        cnt++;
        REP(k, 4) {
            int ki = i + di[k], kj = j + dj[k];
            if (0 <= ki && ki < N && 0 <= kj && kj < M && S[ki][kj] == '.') {
                uf.unite(i * M + j, ki * M + kj);
            }
        }
    }

    S[p][q] = '#';
    return uf.size(p * M + q) == cnt;
}

ll solve() {
    ll ans = 0;
    REP(i, N) REP(j, M) {
        if (can(i, j)) ans++;
    }

    return ans;
}

int main() {
    cin >> N >> M;
    REP(i, N) cin >> S[i];

    cout << solve() << endl;

    return 0;
}
