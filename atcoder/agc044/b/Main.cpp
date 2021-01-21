/*
[agc044] B - Joker
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

const int MAX_N = 500;

int N;
int P[MAX_N * MAX_N];
int h[MAX_N][MAX_N];
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

ll solve() {
    vector<vector<bool>> left(N, vector<bool>(N));
    REP(i, N) REP(j, N) h[i][j] = min(min(i, N - 1 - i), min(j, N - 1 - j));

    ll ans = 0;
    REP(k, N * N) {
        int r = P[k] / N, c = P[k] % N;
        ans += h[r][c];
        left[r][c] = true;

        queue<pii> q;
        q.push({r, c});
        while (!q.empty()) {
            pii p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            REP(n, 4) {
                int ni = i + di[n], nj = j + dj[n];
                int z = h[i][j] + (left[i][j] ? 0 : 1);
                if (0 <= ni && ni < N && 0 <= nj && nj < N && h[ni][nj] > z) {
                    h[ni][nj] = z;
                    q.push({ni, nj});
                }
            }
        }
    }

    return ans;
}

int main() {
    cin >> N;
    REP(k, N * N) {
        cin >> P[k];
        P[k]--;
    }

    cout << solve() << endl;

    return 0;
}
