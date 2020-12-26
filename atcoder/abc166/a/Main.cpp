/*
[abc166] A - A?C
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string s;

string solve() { return s == "ABC" ? "ARC" : "ABC"; }

int main() {
    cin >> s;

    cout << solve() << endl;

    return 0;
}
