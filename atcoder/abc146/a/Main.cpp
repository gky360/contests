/*
[abc146] A - Can't Wait for Holiday
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string S;

ll solve() {
    if (S == "SUN") return 7;
    if (S == "MON") return 6;
    if (S == "TUE") return 5;
    if (S == "WED") return 4;
    if (S == "THU") return 3;
    if (S == "FRI") return 2;
    if (S == "SAT") return 1;
    return 0;
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
