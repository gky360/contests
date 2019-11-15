/*
[abc126] E - 1 or 2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int MAX_M = 1e5;

int N, M;
vector<int> g[MAX_N];
bool visited[MAX_M];

void dfs(int v) {
    if (visited[v]) {
        return;
    }
    visited[v] = true;
    for (int to : g[v]) {
        dfs(to);
    }
}

ll solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << solve() << endl;

    return 0;
}
