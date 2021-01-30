/*
[abc170] B - Crane and Turtle
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
    REP(i, X + 1) if (i * 2 + (X - i) * 4 == Y) return true;
    return false;
}

int main() {
    cin >> X >> Y;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
