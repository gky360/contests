/*
[abc185] D - Stamp
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

const int MAX_M = 2e5;
const int INF = 1e9 + 7;

int N, M;
int A[MAX_M + 2];

ll solve() {
    A[M] = 0, A[M + 1] = N + 1;
    sort(A, A + M + 2);
    REP(i, M + 1) A[i] = A[i + 1] - A[i] - 1;
    int k = INF;
    REP(i, M + 1) {
        if (A[i] > 0) k = min(k, A[i]);
    }
    if (k == INF) return 0;

    ll ans = 0;
    REP(i, M + 1) ans += (A[i] + k - 1) / k;
    return ans;
}

int main() {
    cin >> N >> M;
    REP(i, M) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
