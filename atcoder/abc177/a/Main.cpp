/*
[abc177] A - Don't be late
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

int D, T, S;

bool solve() { return (D + S - 1) / S <= T; }

int main() {
    cin >> D >> T >> S;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
