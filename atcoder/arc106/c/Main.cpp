/*
[arc106] C - Solutions
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

int N, M;

void solve() {
    if (M < 0 || M == N || (M == N - 1 && M > 0)) {
        cout << -1 << endl;
        return;
    }
    if (M == 0) {
        REP(i, N) cout << 2 * i + 1 << " " << 2 * i + 2 << endl;
        return;
    }

    cout << 1 << " " << 2 * M + 4 << endl;
    REP(i, M + 1) cout << 2 * i + 2 << " " << 2 * i + 3 << endl;
    REP(i, N - M - 2)
    cout << 2 * i + 2 * M + 5 << " " << 2 * i + 2 * M + 6 << endl;
    return;
}

int main() {
    cin >> N >> M;

    solve();

    return 0;
}
