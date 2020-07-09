/*
[sumitrust2019] A - November 30
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int M1, D1, M2, D2;

ll solve() { return (M1 != M2) ? 1 : 0; }

int main() {
    cin >> M1 >> D1;
    cin >> M2 >> D2;

    cout << solve() << endl;

    return 0;
}
