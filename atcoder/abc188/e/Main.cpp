/*
[abc188] E - Peddler
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
const ll INF = 1e18;

int N, M;
ll A[MAX_N];
int X[MAX_M], Y[MAX_M];
vector<int> g[MAX_N];
ll m[MAX_N];

ll solve() {
    REP(i, M) g[X[i]].push_back(Y[i]);

    fill(m, m + N, INF);
    REP(v, N) {
        for (int to : g[v]) m[to] = min(m[to], min(m[v], A[v]));
    }
    ll ans = -INF;
    for (int i = 1; i < N; i++) ans = max(ans, A[i] - m[i]);

    return ans;
}

int main() {
    cin >> N >> M;
    REP(i, N) cin >> A[i];
    REP(i, M) cin >> X[i] >> Y[i], X[i]--, Y[i]--;

    cout << solve() << endl;

    return 0;
}
