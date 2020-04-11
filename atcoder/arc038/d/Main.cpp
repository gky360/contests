/*
[arc038] D - 有向グラフと数
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100000;
const int MAX_M = 200000;
const int MAX_X = 1e9;
const int MAX_V = 2 * MAX_N;

int N, M;
int X[MAX_N];
int A[MAX_M], B[MAX_M];
vector<int> g[MAX_V];
int org_deg[MAX_V], deg[MAX_V];
int dp[MAX_V];

bool can(int d) {
    queue<int> q;
    memcpy(deg, org_deg, sizeof(deg));
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++) {
        if (X[i] >= d) {
            dp[i] = 1;
            q.push(i);

            if (deg[i] == 0) {
                dp[i + N] = 0;
                q.push(i + N);
            }
        } else {
            dp[i + N] = 1;
            q.push(i + N);

            if (deg[i] == 0) {
                dp[i] = 0;
                q.push(i);
            }
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (dp[to] > -1) {
                continue;
            }
            deg[to]--;
            if (dp[v] == 0) {
                dp[to] = 1;
                q.push(to);
            } else if (dp[v] == 1) {
                if (deg[to] == 0) {
                    dp[to] = 0;
                    q.push(to);
                }
            }
        }
    }

    return (dp[0] == 1);
}

ll solve() {
    for (int i = 0; i < M; i++) {
        g[B[i] + N].push_back(A[i]);
        g[B[i]].push_back(A[i] + N);
        org_deg[A[i]]++, org_deg[A[i] + N]++;
    }

    int ok = 0, ng = MAX_X + 1;
    while (ng - ok > 1) {
        int m = (ng + ok) / 2;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }

    return ok;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }

    cout << solve() << endl;

    return 0;
}
