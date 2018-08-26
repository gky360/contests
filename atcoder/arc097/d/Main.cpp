/*
[arc097] D - Equals
*/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;
const int MAX_M = 100000;

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
int p[MAX_N];
pii xy[MAX_M];

int solve() {
    UnionFind uf(N);

    for (int i = 0; i < M; i++) {
        uf.unite(xy[i].first, xy[i].second);
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (uf.same(i, p[i])) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < M; i++) {
        cin >> xy[i].first >> xy[i].second;
        xy[i].first--;
        xy[i].second--;
    }

    cout << solve() << endl;

    return 0;
}
