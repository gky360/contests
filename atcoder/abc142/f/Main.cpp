/*
[abc142] F - Pure
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1000;
const int MAX_M = 2000;
const int INF = 1e9;

int N, M;
int A[MAX_M], B[MAX_M];
int dist[MAX_N], from[MAX_N];
vector<int> g[MAX_N], rg[MAX_N];

void bfs(int s) {
    queue<int> q;

    fill(dist, dist + N, INF);
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        g[A[i]].push_back(B[i]);
        rg[B[i]].push_back(A[i]);
    }

    int ans_len = INF;
    vector<int> ans;
    for (int u = 0; u < N; u++) {
        bfs(u);
        for (int v : rg[u]) {
            if (ans_len > dist[v] + 1) {
                ans.clear();
                int w = v;
                while (dist[w] > 0) {
                    ans.push_back(w);
                    w = from[w];
                }
                ans.push_back(u);
                reverse(ALL(ans));
                ans_len = ans.size();
            }
        }
    }

    if (ans_len >= INF) {
        cout << -1 << endl;
        return;
    }

    cout << ans.size() << endl;
    for (int v : ans) {
        cout << v + 1 << endl;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }

    solve();

    return 0;
}
