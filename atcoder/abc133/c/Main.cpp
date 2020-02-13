/*
[abc133] C - Remainder Minimization 2019
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MOD = 2019;

int L, R;

ll solve() {
    R = min(R, L + MOD);

    ll ans = MOD;
    for (int i = L; i <= R; i++) {
        for (int j = i + 1; j <= R; j++) {
            ans = min(ans, (ll)i * j % MOD);
        }
    }

    return ans;
}

int main() {
    cin >> L >> R;

    cout << solve() << endl;

    return 0;
}
