/*
[m-solutions2019] B - Sumo
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

string S;

bool solve() {
    int cnt = 0;
    for (char c : S) {
        if (c == 'o') {
            cnt++;
        }
    }
    return 15 - S.length() + cnt >= 8;
}

int main() {
    cin >> S;

    cout << (solve() ? "YES" : "NO") << endl;

    return 0;
}
