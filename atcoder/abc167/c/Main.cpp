/*
[abc167] C - Skill Up
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

const int MAX_N = 12;
const int MAX_M = 12;
const int INF = 1e9;

int N, M, X;
int C[MAX_N], A[MAX_N][MAX_M];

int can(int pat) {
    vector<int> a(M);
    int s = 0;
    REP(i, N) {
        if ((pat >> i) & 1) {
            s += C[i];
            REP(j, M) a[j] += A[i][j];
        }
    }
    REP(j, M) if (a[j] < X) return INF;
    return s;
}

ll solve() {
    int ans = INF;
    REP(pat, (1 << N)) ans = min(ans, can(pat));
    return ans == INF ? -1 : ans;
}

int main() {
    cin >> N >> M >> X;
    REP(i, N) {
        cin >> C[i];
        REP(j, M) cin >> A[i][j];
    }

    cout << solve() << endl;

    return 0;
}
