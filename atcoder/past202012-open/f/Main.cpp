/*
[past202012-open] F - Dangerous Chemicals
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

const int MAX_M = 364;

int N, M;
int A[3][MAX_M];

ll solve() {
    int ans = 0;
    REP(p, 1 << N) {
        set<int> s;
        REP(i, M) {
            int cnt = 0, t = -1;
            REP(k, 3) {
                if ((p >> A[k][i]) & 1) {
                    cnt++;
                } else {
                    t = A[k][i];
                }
            }
            if (cnt == 2) s.insert(t);
        }
        ans = max(ans, (int)s.size());
    }

    return ans;
}

int main() {
    cin >> N >> M;
    REP(i, M)
    cin >> A[0][i] >> A[1][i] >> A[2][i], A[0][i]--, A[1][i]--, A[2][i]--;

    cout << solve() << endl;

    return 0;
}
