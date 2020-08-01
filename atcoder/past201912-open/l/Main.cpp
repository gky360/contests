/*
[past201912-open] L - グラデーション / Gradation
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 30;
const int MAX_M = 5;
const double INF = 1e30;

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

typedef tuple<double, int, int> Edge;

int N, M;
int X[MAX_M + MAX_N], Y[MAX_M + MAX_N], C[MAX_M + MAX_N];

double calc(ll pat, vector<Edge> &es) {
    double ret = 0;
    UnionFind uf(M + N);
    for (auto &e : es) {
        double cost;
        int from, to;
        tie(cost, from, to) = e;
        if (((pat >> from) & 1) || ((pat >> to) & 1)) {
            continue;
        }
        if (!uf.same(from, to)) {
            uf.unite(from, to);
            ret += cost;
        }
    }

    return ret;
}

double solve() {
    vector<Edge> es;
    for (int i = 0; i < M + N; i++) {
        for (int j = i + 1; j < M + N; j++) {
            double d = sqrt((X[i] - X[j]) * (X[i] - X[j]) +
                            (Y[i] - Y[j]) * (Y[i] - Y[j]));
            if (C[i] != C[j]) {
                d *= 10;
            }
            es.push_back((Edge){d, i, j});
        }
    }
    sort(ALL(es));

    double ans = INF;
    for (ll pat = 0; pat < (1LL << M); pat++) {
        ans = min(ans, calc(pat, es));
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> X[M + i] >> Y[M + i] >> C[M + i];
    }
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i] >> C[i];
    }

    cout << fixed << setprecision(12) << solve() << endl;

    return 0;
}
