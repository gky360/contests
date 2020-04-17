/*
[abc139] E - League
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1000;

int N;
int A[MAX_N][MAX_N - 1];
vector<int> g[MAX_N * (MAX_N - 1) / 2];
int color[MAX_N * (MAX_N - 1) / 2];
int dep[MAX_N * (MAX_N - 1) / 2];

int get_v(int x, int y) {
    if (x < y) {
        swap(x, y);
    }
    return x * (x - 1) / 2 + y;
}

bool dfs(int v) {
    color[v] = 1;
    for (int to : g[v]) {
        if (color[to] == 1) {
            return false;
        }
        if (!color[to] && !dfs(to)) {
            return false;
        }
        dep[v] = max(dep[v], dep[to] + 1);
    }
    color[v] = 2;
    return true;
}

ll solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N - 1; j++) {
            int v0 = get_v(i, A[i][j - 1]), v1 = get_v(i, A[i][j]);
            g[v0].push_back(v1);
        }
    }

    for (int v = 0; v < N * (N - 1) / 2; v++) {
        if (!color[v] && !dfs(v)) {
            return -1;
        }
    }

    int ans = *max_element(dep, dep + N * (N - 1) / 2) + 1;

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    cout << solve() << endl;

    return 0;
}
