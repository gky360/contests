/*
[abl] C - Connect Cities
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

const int MAX_N = 100000;
const int MAX_M = 100000;

int N, M;
int A[MAX_M], B[MAX_M];

vector<int> g[MAX_N];
bool visited[MAX_N];

void dfs(int v) {
    if (visited[v]) return;
    visited[v] = true;
    for (int to : g[v]) dfs(to);
}

ll solve() {
    REP(i, M) {
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }

    ll ans = 0;
    REP(i, N) {
        if (!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    ans--;

    return ans;
}

int main() {
    cin >> N >> M;
    REP(i, M) cin >> A[i] >> B[i], A[i]--, B[i]--;

    cout << solve() << endl;

    return 0;
}
