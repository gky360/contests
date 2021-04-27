/*
[abc178] E - Dist Max
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
ll x[MAX_N], y[MAX_N];
ll z[MAX_N], w[MAX_N];

ll solve() {
    REP(i, N) z[i] = x[i] + y[i], w[i] = x[i] - y[i];
    sort(z, z + N);
    sort(w, w + N);

    ll ans = max(z[N - 1] - z[0], w[N - 1] - w[0]);
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> x[i] >> y[i];

    cout << solve() << endl;

    return 0;
}
