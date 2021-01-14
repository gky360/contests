/*
[abc168] D - .. (Double Dots)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;

int N, M;
vector<int> g[MAX_N];
bool visited[MAX_N];
int ans[MAX_N];

bool solve() {
    queue<int> q;

    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (!visited[to]) {
                visited[to] = true;
                q.push(to);
                ans[to] = v;
            }
        }
    }

    return true;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    if (solve()) {
        cout << "Yes" << endl;
        for (int i = 1; i < N; i++) {
            cout << ans[i] + 1 << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}
