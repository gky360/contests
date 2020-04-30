/*
[tenka1-2015-final] F - 根付き木のみさわさん
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MAX_M = 1e5;
const int INF = 1e9;

template <typename T>
class RMQ {
public:
    int n;
    vector<T> data;
    RMQ(int _n) {
        n = 1;
        while (n < _n) {
            n <<= 1;
        }
        data.resize(2 * n - 1);
        fill(data.begin(), data.end(), INF);
    }
    void update(int k, T a) {
        k += n - 1;
        data[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = min(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }
    T query(int a, int b) { return query(a, b, 0, 0, n); }

private:
    T query(int a, int b, int k, int l, int r) {  // [a, b), [l, r)
        if (r <= a || b <= l) {
            return INF;
        }
        if (a <= l && r <= b) {
            return data[k];
        }
        return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
                   query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

int N;
int Q;
int M, K;
int vq[MAX_M];
vector<int> g[MAX_N];
int id[MAX_N], vs[MAX_N * 2];
int dep[MAX_N * 2];
RMQ<int> rmq(MAX_N * 2);

void euler_dfs(int v, int par, int d, int &k) {
    id[v] = k;
    vs[k] = v;
    dep[k++] = d;
    for (int to : g[v]) {
        if (to == par) continue;
        euler_dfs(to, v, d + 1, k);
        vs[k] = v;
        dep[k++] = d;
    }
}

void init() {
    int k = 0;
    euler_dfs(0, -1, 0, k);

    for (int i = 0; i < N * 2 - 1; i++) {
        rmq.update(i, dep[i]);
    }
}

ll solve() {
    for (int i = 0; i < M; i++) {
        vq[i] = id[vq[i]];
    }
    sort(vq, vq + M);

    int ans = 0;
    for (int i = 0; i + K - 1 < M; i++) {
        ans = max(ans, rmq.query(vq[i], vq[i + K - 1] + 1));
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    init();

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> M >> K;
        for (int j = 0; j < M; j++) {
            cin >> vq[j];
            vq[j]--;
        }
        cout << solve() << endl;
    }

    return 0;
}
