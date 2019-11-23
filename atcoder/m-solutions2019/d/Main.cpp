/*
[m-solutions2019] D - Maximum Sum of Minimum
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 10000;

int N;
int c[MAX_N];
vector<int> g[MAX_N];
int cid = 0;
int ans[MAX_N];

void dfs(int v, int par = -1) {
    ans[v] = c[cid++];
    for (int to : g[v]) {
        if (to == par) {
            continue;
        }
        dfs(to, v);
    }
}

ll solve() {
    sort(c, c + N, greater<int>());
    dfs(0);
    return accumulate(c + 1, c + N, 0);
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    cout << solve() << endl;
    for (int i = 0; i < N; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}
