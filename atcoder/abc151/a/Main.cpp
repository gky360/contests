/*
[abc151] A - Next Alphabet
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

char C;

char solve() { return C + 1; }

int main() {
    cin >> C;

    cout << solve() << endl;

    return 0;
}
