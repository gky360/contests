/*
[abc149] A - Strings
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string S, T;

string solve() { return T + S; }

int main() {
    cin >> S >> T;

    cout << solve() << endl;

    return 0;
}
