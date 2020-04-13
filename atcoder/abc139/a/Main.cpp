/*
[abc139] A - Tenki
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string S, T;

ll solve() {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (S[i] == T[i]) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    cin >> S >> T;

    cout << solve() << endl;

    return 0;
}
