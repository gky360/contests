/*
[abc129] A - Airplane
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int d[3];

ll solve() { return accumulate(d, d + 3, 0) - *max_element(d, d + 3); }

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> d[i];
    }

    cout << solve() << endl;

    return 0;
}
