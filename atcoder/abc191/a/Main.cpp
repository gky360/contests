/*
[abc191] A - Vanishing Pitch
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

int V, T, S, D;

bool solve() { return D < V * T || V * S < D; }

int main() {
    cin >> V >> T >> S >> D;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
