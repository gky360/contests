// AtCoder Regular Contest 076
// D - Built?

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pii> plii;


const int MAX_N = 100000;

class UnionFind {
    public:
        vector<int> data;
        void init(int size) {
            data = vector<int>(size, -1);
        }
        bool unite(int x, int y) {
            x = root(x); y = root(y);
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
        bool same(int x, int y) {
            return root(x) == root(y);
        }
        int root(int x) {
            return data[x] < 0 ? x : data[x] = root(data[x]);
        }
        int size(int x) {
            return -data[root(x)];
        }
};


int N;
pli X[MAX_N], Y[MAX_N];
priority_queue<plii, vector<plii>, greater<plii>> q;
UnionFind uf;
ll ans;

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i].first >> Y[i].first;
        X[i].second = Y[i].second = i;
    }
    uf.init(N);
    sort(X, X + N);
    sort(Y, Y + N);

    for (int i = 1; i < N; i++) {
        q.push(make_pair(abs(X[i - 1].first - X[i].first), pii(X[i - 1].second, X[i].second)));
        q.push(make_pair(abs(Y[i - 1].first - Y[i].first), pii(Y[i - 1].second, Y[i].second)));
    }

    ans = 0;
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        if (uf.same(p.second.first, p.second.second)) {
            continue;
        }
        ans += p.first;
        uf.unite(p.second.first, p.second.second);
    }

    cout << ans << endl;

    return 0;

}



