/*
[abc175] A - Rainy Season
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

ll solve() {
    char p = '_';
    int cnt = 0;
    int ans = 0;
    for (char c : S) {
        if (c != p) cnt = 0;
        if (c == 'R') cnt++;
        ans = max(ans, cnt);
        p = c;
    }

    return ans;
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
