/*
[abc188] A - Three-Point Shot
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

int X, Y;

bool solve() {
    if (X < Y) swap(X, Y);

    return X < (Y + 3);
}

int main() {
    cin >> X >> Y;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
