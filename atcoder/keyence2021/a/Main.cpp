/*
[keyence2021] A - Two Sequences 2
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

int N;
ll a[MAX_N], b[MAX_N];

void solve() {
    ll ma = 0, pc = 0;
    REP(i, N) {
        ma = max(ma, a[i]);
        ll ans = max(pc, ma * b[i]);
        pc = ans;
        cout << ans << endl;
    }
}

int main() {
    cin >> N;
    REP(i, N) cin >> a[i];
    REP(i, N) cin >> b[i];

    solve();

    return 0;
}
