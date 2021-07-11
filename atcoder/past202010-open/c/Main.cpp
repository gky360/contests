/*
[past202010-open] C - 隣接カウント
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

const int MAX_N = 30;

int N, M;
string S[MAX_N];
int ans[MAX_N][MAX_N];

void solve() {
    REP(i, N) REP(j, M) {
        for (int p = max(0, i - 1); p < min(N, i + 2); p++) {
            for (int q = max(0, j - 1); q < min(M, j + 2); q++) {
                ans[i][j] += S[p][q] == '#' ? 1 : 0;
            }
        }
    }

    REP(i, N) {
        REP(j, M) cout << ans[i][j];
        cout << endl;
    }
}

int main() {
    cin >> N >> M;
    REP(i, N) cin >> S[i];

    solve();

    return 0;
}
