/*
[abc182] E - Akari
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

const int MAX_H = 1500;
const int MAX_W = 1500;
const int MAX_N = 5e5;
const int MAX_M = 1e5;

int H, W, N, M;
int A[MAX_N], B[MAX_N], C[MAX_M], D[MAX_M];
int m[MAX_H + 2][MAX_W + 2];
int dh[4] = {-1, 0, 1, 0}, dw[4] = {0, 1, 0, -1};

ll solve() {
    REP(i, M) m[C[i]][D[i]] = -1;
    REP(i, H + 2) m[i][0] = m[i][W + 1] = -1;
    REP(j, W + 2) m[0][j] = m[H + 1][j] = -1;

    ll ans = 0;
    REP(n, N) {
        REP(k, 4) {
            int x = 1 << (k % 2);
            for (int a = A[n] + dh[k], b = B[n] + dw[k]; (m[a][b] & x) == 0;
                 a += dh[k], b += dw[k]) {
                if (m[a][b] == 0) ans++;
                m[a][b] |= x;
            }
        }
        if (m[A[n]][B[n]] == 0) {
            m[A[n]][B[n]] = 3;
            ans++;
        }
    }

    return ans;
}

int main() {
    cin >> H >> W >> N >> M;
    REP(i, N) cin >> A[i] >> B[i];
    REP(i, M) cin >> C[i] >> D[i];

    cout << solve() << endl;

    return 0;
}
