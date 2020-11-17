/*
[abc160] D - Line++
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

const int MAX_N = 2e3;

int N, X, Y;
int ans[MAX_N];

int calc(int i, int j) { return min(j - i, abs(X - i) + abs(Y - j) + 1); }

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans[calc(i, j)]++;
        }
    }
    for (int k = 1; k < N; k++) {
        cout << ans[k] << endl;
    }
}

int main() {
    cin >> N >> X >> Y;
    X--, Y--;

    solve();

    return 0;
}
