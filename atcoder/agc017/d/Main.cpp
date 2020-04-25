/*
[agc017] D - Game on Tree
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100000;

int N;
vector<int> g[MAX_N];

int dfs(int v, int par = -1) {
    int grundy = 0;
    for (int to : g[v]) {
        if (to == par) {
            continue;
        }
        grundy ^= dfs(to, v) + 1;
    }
    return grundy;
}

bool solve() { return dfs(0); }

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    cout << (solve() ? "Alice" : "Bob") << endl;

    return 0;
}
