/*
[abc131] A - Security
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

string S;

bool solve() {
    char pc = '_';
    for (char c : S) {
        if (c == pc) {
            return false;
        }
        pc = c;
    }

    return true;
}

int main() {
    cin >> S;

    cout << (solve() ? "Good" : "Bad") << endl;

    return 0;
}
