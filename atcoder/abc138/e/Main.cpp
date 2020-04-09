/*
[abc138] E - Strings of Impurity
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_S = 1e5;
const int INF = 1e9;

string s, t;
int d['z' - 'a' + 1][MAX_S];

ll solve() {
    int sl = s.length();
    string ss = s + s;

    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < sl;) {
            size_t idx = ss.find(c, i);
            if (idx == string::npos) {
                fill(d[c - 'a'], d[c - 'a'] + sl, INF);
                break;
            }
            for (; i < sl && i <= (int)idx; i++) {
                d[c - 'a'][i] = idx - i;
            }
        }
    }

    ll ans = 0;
    for (char c : t) {
        int dd = d[c - 'a'][ans % sl];
        if (dd >= INF) {
            return -1;
        }
        ans += dd + 1;
    }

    return ans;
}

int main() {
    cin >> s;
    cin >> t;

    cout << solve() << endl;

    return 0;
}
