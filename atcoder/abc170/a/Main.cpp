/*
[abc170] A - Five Variables
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

int x[5];

ll solve() {
    REP(i, 5) if (x[i] == 0) return i + 1;
    return -1;
}

int main() {
    REP(i, 5) cin >> x[i];

    cout << solve() << endl;

    return 0;
}
