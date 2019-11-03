/*
[diverta2019] C - AB Substrings
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e4;

int N;
string s[MAX_N];

ll solve() {
    int c1 = 0, c2 = 0, c3 = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (int)s[i].length() - 1; j++) {
            if (s[i][j] == 'A' && s[i][j + 1] == 'B') {
                ans++;
            }
        }
        if (s[i][0] == 'B') {
            if (s[i].back() == 'A') {
                c1++;
            } else {
                c2++;
            }
        } else if (s[i].back() == 'A') {
            c3++;
        }
    }

    if (c1 == 0) {
        ans += min(c2, c3);
    } else if (c2 + c3 > 0) {
        ans += c1 + min(c2, c3);
    } else {
        ans += c1 - 1;
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    cout << solve() << endl;

    return 0;
}
