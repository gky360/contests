/*
[past202012-open] I - Evacuation Plan
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

const int MAX_N = 2e5;
const int MAX_M = 2e5;
const int INF = 1e9;

int N, M, K;
int H[MAX_N];
int C[MAX_N];
int A[MAX_M], B[MAX_M];
vector<int> g[MAX_N];

void solve() {
    int ans[MAX_N];
    REP(j, M) {
        if (H[A[j]] > H[B[j]]) swap(A[j], B[j]);
        g[A[j]].push_back(B[j]);
    }
    fill(ans, ans + N, INF);
    queue<int> q;
    REP(i, K) {
        ans[C[i]] = 0;
        q.push(C[i]);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (ans[to] == INF) {
                ans[to] = ans[v] + 1;
                q.push(to);
            }
        }
    }

    REP(i, N) cout << (ans[i] == INF ? -1 : ans[i]) << endl;
}

int main() {
    cin >> N >> M >> K;
    REP(i, N) cin >> H[i];
    REP(i, K) cin >> C[i], C[i]--;
    REP(j, M) cin >> A[j] >> B[j], A[j]--, B[j]--;

    solve();

    return 0;
}
