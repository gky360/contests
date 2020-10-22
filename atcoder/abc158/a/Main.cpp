/*
[abc158] A - Station and Bus
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string S;

bool solve() { return !(S == "AAA" || S == "BBB"); }

int main() {
    cin >> S;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
