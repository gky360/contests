/*
[abc130] A - Rounding
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int X, A;

ll solve() { return X < A ? 0 : 10; }

int main() {
    cin >> X >> A;

    cout << solve() << endl;

    return 0;
}
