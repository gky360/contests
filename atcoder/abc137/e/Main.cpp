/*
[abc137] E - Coins Respawn
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2500;
const int MAX_M = 5000;
const int INF = 1e9;

const int MAX_V = MAX_N;

int N, M, P;
int A[MAX_M], B[MAX_M], C[MAX_M];
vector<int> g[2][MAX_N];
bool visited[2][MAX_N];
int d[MAX_V];

void dfs(int r, int v) {
    if (visited[r][v]) {
        return;
    }
    visited[r][v] = true;

    for (int to : g[r][v]) {
        dfs(r, to);
    }
}

bool bellman_ford(int s, int V, int E) {
    fill(d, d + N, INF);
    d[s] = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            if (d[A[j]] < INF && d[B[j]] > d[A[j]] + C[j]) {
                d[B[j]] = d[A[j]] + C[j];
                if (i == V - 1 && visited[0][B[j]] && visited[1][B[j]]) {
                    return true;
                }
            }
        }
    }
    return false;
}

ll solve() {
    for (int i = 0; i < M; i++) {
        C[i] = -(C[i] - P);
        g[0][A[i]].push_back(B[i]);
        g[1][B[i]].push_back(A[i]);
    }

    dfs(0, 0);
    dfs(1, N - 1);

    if (bellman_ford(0, N, M)) {
        return -1;
    }

    return max(0, -d[N - 1]);
}

int main() {
    cin >> N >> M >> P;
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--, B[i]--;
    }

    cout << solve() << endl;

    return 0;
}
