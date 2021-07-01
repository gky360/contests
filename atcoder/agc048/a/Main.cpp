/*
[agc048] A - atcoder < S
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

int T;

ll solve(string s) {
    if (s > "atcoder") return 0;
    REP(i, s.length()) {
        if (s[i] != 'a') {
            if (s[i] <= 't') return i;
            return i - 1;
        }
    }
    return -1;
}

int main() {
    cin >> T;
    REP(i, T) {
        string S;
        cin >> S;
        cout << solve(S) << endl;
    }

    return 0;
}
