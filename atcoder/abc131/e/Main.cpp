/*
[abc131] E - Friendships
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N, K;

void add_edge(int u, int v) { cout << u + 1 << " " << v + 1 << endl; }

void solve() {
    int m = (N - 1) * (N - 2) / 2 - K;
    if (m < 0) {
        cout << -1 << endl;
        return;
    }

    int M = N - 1 + m;
    cout << M << endl;

    for (int i = 1; i < N; i++) {
        add_edge(0, i);
    }

    int cnt = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N && cnt < m; j++, cnt++) {
            add_edge(i, j);
        }
    }
}

int main() {
    cin >> N >> K;

    solve();

    return 0;
}
