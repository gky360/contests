/*
[abc178] A - Not
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

int x;

ll solve() { return x ^ 1; }

int main() {
    cin >> x;

    cout << solve() << endl;

    return 0;
}
