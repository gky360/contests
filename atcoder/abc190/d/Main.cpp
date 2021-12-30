/*
[abc190] D - Staircase Sequences
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

ll N;

ll solve() {
    while (N % 2 == 0) N /= 2;
    ll ans = 0;
    for (ll x = 1; x * x <= N; x++) {
        if (N % x == 0) ans += (N / x == x) ? 1 : 2;
    }
    ans *= 2;
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
