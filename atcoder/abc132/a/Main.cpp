/*
[abc132] A - Fifty-Fifty
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

string S;

bool solve() {
    sort(S.begin(), S.end());

    return (S[0] == S[1] && S[2] == S[3] && S[0] != S[2]);
}

int main() {
    cin >> S;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
