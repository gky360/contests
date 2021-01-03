/*
[abc167] A - Registration
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

string S, T;

bool solve() {
    return T.length() == S.length() + 1 && T.substr(0, T.length() - 1) == S;
}

int main() {
    cin >> S >> T;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
