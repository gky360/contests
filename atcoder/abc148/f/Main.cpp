/*
[abc148] F - Playing Tag on Tree
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
int TK, AO;
vector<int> g[MAX_N];
int dep[2][MAX_N];

void dfs(int k, int v, int par = -1, int d = 0) {
    dep[k][v] = d;
    for (int to : g[v]) {
        if (to == par) {
            continue;
        }
        dfs(k, to, v, d + 1);
    }
}

ll solve() {
    dfs(0, TK);
    dfs(1, AO);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (dep[0][i] < dep[1][i]) {
            ans = max(ans, dep[1][i] - 1);
        }
    }

    return ans;
}

int main() {
    cin >> N >> TK >> AO;
    TK--, AO--;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    cout << solve() << endl;

    return 0;
}
