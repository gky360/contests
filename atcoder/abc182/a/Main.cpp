/*
[abc182] A - twiblr
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

int A, B;

ll solve() {
    ll ans = 2 * A + 100 - B;
    return ans;
}

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
