/*
[abc177] B - Substring
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

ll solve() {
    int ans = T.length();
    REP(i, S.length() - T.length() + 1) {
        int cnt = 0;
        REP(j, T.length()) {
            if (S[i + j] != T[j]) cnt++;
        }
        ans = min(ans, cnt);
    }

    return ans;
}

int main() {
    cin >> S;
    cin >> T;

    cout << solve() << endl;

    return 0;
}
