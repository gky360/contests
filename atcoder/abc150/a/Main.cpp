/*
[abc150] A - 500 Yen Coins
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int K, X;

bool solve() { return 500 * K >= X; }

int main() {
    cin >> K >> X;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
