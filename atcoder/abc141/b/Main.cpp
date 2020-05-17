/*
[abc141] B - Tap Dance
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string S;

bool solve() {
    for (int i = 0; i < (int)S.length(); i++) {
        if (i % 2 == 0 && S[i] == 'L') {
            return false;
        }
        if (i % 2 == 1 && S[i] == 'R') {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> S;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
