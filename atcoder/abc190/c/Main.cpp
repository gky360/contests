/*
[abc190] C - Bowls and Dishes
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

const int MAX_N = 100;
const int MAX_M = 100;
const int MAX_K = 16;

int N, M;
int A[MAX_M], B[MAX_M];
int K;
int C[MAX_K], D[MAX_K];

ll solve() {
    int ans = 0;
    REP(pat, 1 << K) {
        vector<bool> has(N);
        REP(k, K) has[((pat >> k) & 1) ? C[k] : D[k]] = true;
        int ret = 0;
        REP(m, M) if (has[A[m]] && has[B[m]]) ret++;
        ans = max(ans, ret);
    }

    return ans;
}

int main() {
    cin >> N >> M;
    REP(i, M) cin >> A[i] >> B[i], A[i]--, B[i]--;
    cin >> K;
    REP(i, K) cin >> C[i] >> D[i], C[i]--, D[i]--;

    cout << solve() << endl;

    return 0;
}
