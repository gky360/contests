/*
[abc174] B - Distance
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
ll D;
ll X[MAX_N], Y[MAX_N];

ll solve() {
    ll ans = 0;
    REP(i, N) {
        if (X[i] * X[i] + Y[i] * Y[i] <= D * D) ans++;
    }
    return ans;
}

int main() {
    cin >> N >> D;
    REP(i, N) cin >> X[i] >> Y[i];

    cout << solve() << endl;

    return 0;
}
