/*
[abc174] A - Air Conditioner
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

int X;

bool solve() { return X >= 30; }

int main() {
    cin >> X;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
