/*
[abc179] A - Plural Form
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
    if (S[S.length() - 1] != 's') return S + "s";
    return S + "es";
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
