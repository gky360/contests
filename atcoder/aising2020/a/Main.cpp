/*
[aising2020] A - Number of Multiples
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

int L, R, d;

ll solve() {
    ll ans = 0;
    for (int i = L; i <= R; i++) {
        if (i % d == 0) ans++;
    }

    return ans;
}

int main() {
    cin >> L >> R >> d;

    cout << solve() << endl;

    return 0;
}
