/*
[past202012-open] A - OX Game
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

string S;

string solve() {
    if (S.find("ooo") != string::npos) return "o";
    if (S.find("xxx") != string::npos) return "x";
    return "draw";
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
