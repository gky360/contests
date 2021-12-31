/*
[abc190] E - Magical Ornament
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MAX_M = 1e5;
const int MAX_K = 17;
const int INF = 1e8;

int N, M;
int A[MAX_M], B[MAX_M];
int K;
int C[MAX_K];
vector<int> g[MAX_N];
int d[MAX_K][MAX_K];

ll solve() {
    REP(j, M) g[A[j]].push_back(B[j]), g[B[j]].push_back(A[j]);

    REP(k, K) {
        vector<int> dist(MAX_N, INF);
        queue<int> q;
        dist[C[k]] = 0;
        q.push(C[k]);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) {
                if (dist[to] > dist[v] + 1) dist[to] = dist[v] + 1, q.push(to);
            }
        }
        REP(kk, K) d[k][kk] = dist[C[kk]];
    }

    vector<vector<int>> dp(1 << K, vector<int>(K, INF));
    REP(k, K) dp[1 << k][k] = 0;
    for (int p = 1; p < (1 << K); p++) {
        REP(k, K) {
            if (!(p & (1 << k))) continue;
            REP(j, K) {
                dp[p][k] = min(dp[p][k], dp[p ^ (1 << k)][j] + d[j][k]);
            }
        }
    }

    int ans = INF;
    REP(k, K) ans = min(ans, dp[(1 << K) - 1][k] + 1);
    if (ans == INF) ans = -1;

    return ans;
}

int main() {
    cin >> N >> M;
    REP(i, M) cin >> A[i] >> B[i], A[i]--, B[i]--;
    cin >> K;
    REP(i, K) cin >> C[i], C[i]--;

    cout << solve() << endl;

    return 0;
}
