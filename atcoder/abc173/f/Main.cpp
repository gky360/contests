/*
[abc173] F - Intervals on Tree
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

const int MAX_N = 2e5;

ll N;
int u[MAX_N - 1], v[MAX_N - 1];

ll solve() {
    ll ans = N * (N + 1) * (N + 2) / 6;
    REP(i, N - 1) {
        if (u[i] > v[i]) swap(u[i], v[i]);
        ans -= u[i] * (N - v[i] + 1);
    }
    return ans;
}

int main() {
    cin >> N;
    REP(i, N - 1) cin >> u[i] >> v[i];

    cout << solve() << endl;

    return 0;
}
