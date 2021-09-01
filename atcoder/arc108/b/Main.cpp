/*
[arc108] B - Abbreviate Fox
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

int N;
string s;

ll solve() {
    string t;
    for (char c : s) {
        t.push_back(c);
        if (t.substr(max(0, (int)t.length() - 3)) == "fox")
            t.erase(t.length() - 3);
    }

    ll ans = t.length();
    return ans;
}

int main() {
    cin >> N >> s;

    cout << solve() << endl;

    return 0;
}
