/*
[arc107] E - Mex Mat
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

const int MAX_N = 500000;

int N;
vector<vector<int>> a;
int mex[3][3] = {
    {1, 2, 1},
    {2, 0, 0},
    {1, 0, 0},
};
ll ans[3];

void solve() {
    REP(j, N) ans[a[0][j]]++;
    for (int i = 1; i < N; i++) ans[a[i][0]]++;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < (i < 4 ? N : min(4, N)); j++) {
            a[i][j] = mex[a[i - 1][j]][a[i][j - 1]];
            ans[a[i][j]]++;
        }
    }
    for (int j = 4; j < N; j++) ans[a[3][j - 1]] += N - j;
    for (int i = 5; i < N; i++) ans[a[i - 1][3]] += N - i;

    REP(k, 3) cout << ans[k] << " ";
    cout << endl;
}

int main() {
    cin >> N;

    a.resize(N);
    a[0].resize(N);
    REP(j, N) cin >> a[0][j];
    for (int i = 1; i < N; i++) {
        a[i].resize(i < 4 ? N : min(4, N));
        cin >> a[i][0];
    }

    solve();

    return 0;
}
