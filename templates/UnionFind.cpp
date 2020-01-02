// UnionFind
// int

#include <bits/stdc++.h>
using namespace std;

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

int main() {
    return 0;
}
