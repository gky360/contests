/*
[agc050] A - AtCoder Jumper
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

const int MAX_N = 1000;

int N;
int ans[MAX_N][2];

void solve() { REP(i, N) ans[i][0] = 2 * i + 1, ans[i][1] = 2 * i + 2; }

int main() {
    cin >> N;

    solve();
    REP(i, N) cout << ans[i][0] % N + 1 << " " << ans[i][1] % N + 1 << endl;

    return 0;
}
