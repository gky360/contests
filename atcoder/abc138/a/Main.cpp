/*
[abc138] A - Red or Not
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int a;
string s;

string solve() { return a >= 3200 ? s : "red"; }

int main() {
    cin >> a;
    cin >> s;

    cout << solve() << endl;

    return 0;
}
