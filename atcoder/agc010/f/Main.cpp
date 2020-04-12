/*
[agc010] F - Tree Game
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 3000;
const int INF = 1e9 + 1;

int N;
int A[MAX_N];
vector<int> g[MAX_N];

int dfs(int v, int par = -1) {
    for (int to : g[v]) {
        if (to == par) {
            continue;
        }
        if (dfs(to, v) < A[v]) {
            return INF;
        }
    }
    return A[v];
}

void solve() {
    for (int i = 0; i < N; i++) {
        if (dfs(i) >= INF) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    solve();

    return 0;
}
