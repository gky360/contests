/*
[abc134] A - Dodecagon
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int r;

ll solve() { return 3 * r * r; }

int main() {
    cin >> r;

    cout << solve() << endl;

    return 0;
}
