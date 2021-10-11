/*
[abc185] A - ABC Preparation
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

int A[4];

ll solve() {
    ll ans = *min_element(A, A + 4);
    return ans;
}

int main() {
    REP(i, 4) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
