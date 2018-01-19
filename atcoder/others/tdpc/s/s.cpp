// TDPC
// S - マス目

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

class UnionFind {
public:
    vector<int> data;
    void init(int size) { data = vector<int>(size, -1); }
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
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    int size(int x) { return -data[root(x)]; }
};

const int MAX_H = 6;
const int MAX_W = 100;
constexpr int MOD = 1e9 + 7;

int H, W;
int pw[MAX_H + 2];
int dp[2][1 << (3 * MAX_H)];

int main() {
    cin >> H >> W;

    pw[0] = 1;
    for (int i = 1; i <= H + 1; i++) {
        pw[i] = (pw[i - 1] * 7);
    }

    for (int i = 0; i < (1 << H); i++) {
        if ((i & 1) == 0) {
            continue;
        }
        int s = 1;
        int label = 1;
        for (int j = 1; j < H; j++) {
            if ((i >> j) & 1) {
                s += label * pw[j];
            } else if ((i >> (j - 1)) & 1) {
                label++;
            }
        }
        dp[0][s] = 1;
    }

    for (int i = 0; i < W - 1; i++) {
        memset(dp[1], 0, sizeof(dp[1]));
        for (int j = 0; j < pw[H]; j++) {
            if (dp[0][j] == 0) {
                continue;
            }
            for (int k = 0; k < (1 << H); k++) {
                UnionFind uf;
                uf.init(H);
                int p[MAX_H];
                memset(p, 0, sizeof(p));
                for (int l = 0; l < H; l++) {
                    if (((k >> l) & 1) == 0) {
                        continue;
                    }
                    int u = j / pw[l] % 7;
                    if (u == 1) {
                        p[l] = 1;
                    }

                    for (int m = l + 1; m < H; m++) {
                        if (((k >> m) & 1) == 0) {
                            continue;
                        }
                        if (m == l + 1) {
                            uf.unite(l, m);
                        } else {
                            int v = j / pw[m] % 7;
                            if (u > 0 && u == v) {
                                uf.unite(l, m);
                            }
                        }
                    }
                }

                for (int l = 0; l < H; l++) {
                    if (p[l] == 1) {
                        p[uf.root(l)] = 1;
                    }
                }
                int nj = 0;
                int label = 2;
                for (int l = 0; l < H; l++) {
                    if (((k >> l) & 1) == 0) {
                        continue;
                    }
                    int u = uf.root(l);
                    if (p[u] == 0) {
                        p[u] = label++;
                    }
                    nj += p[u] * pw[l];
                }
                (dp[1][nj] += dp[0][j]) %= MOD;
            }
        }
        swap(dp[0], dp[1]);
    }

    int ans = 0;
    for (int i = 0; i < pw[H]; i++) {
        if (i / pw[H - 1] % 7 == 1) {
            (ans += dp[0][i]) %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
