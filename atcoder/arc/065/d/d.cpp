// AtCoder Regular Contest 065
// D - 連結 / Connectivity

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> PII;


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


int N, KL[2];
UnionFind uf[2];
map<PII, int> mp;

int main() {

    PII p;
    int a, b;

    scanf("%d%d%d", &N, &KL[0], &KL[1]);
    for (int j = 0; j < 2; j++) {
        uf[j].init(N);
        for (int i = 0; i < KL[j]; i++) {
            scanf("%d%d", &a, &b);
            uf[j].unite(a - 1, b - 1);
        }
    }

    for (int i = 0; i < N; i++) {
        p = PII(uf[0].root(i), uf[1].root(i));
        mp[p] = mp[p] + 1;
    }

    for (int i = 0; i < N; i++) {
        p = PII(uf[0].root(i), uf[1].root(i));
        printf("%d%c", mp[p], i == N - 1 ? '\n' : ' ');
    }

    return 0;

}



