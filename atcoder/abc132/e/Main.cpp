/*
[abc132] E - Hopscotch Addict
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int INF = 1e9;

int N, M;
int u[MAX_N], v[MAX_N];
int S, T;

vector<int> g[MAX_N];
queue<pii> q;
int dist[3][MAX_N];

ll solve() {
    for (int i = 0; i < M; i++) {
        g[u[i]].push_back(v[i]);
    }

    for (int i = 0; i < 3; i++) {
        fill(dist[i], dist[i] + N, INF);
    }
    q.push({0, S});  // d, v
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        int d = p.first;
        int v = p.second;
        if (dist[d % 3][v] > d) {
            dist[d % 3][v] = d;
            for (int to : g[v]) {
                q.push({d + 1, to});
            }
        }
    }

    return dist[0][T] < INF ? dist[0][T] / 3 : -1;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
    }
    cin >> S >> T;
    S--, T--;

    cout << solve() << endl;

    return 0;
}
