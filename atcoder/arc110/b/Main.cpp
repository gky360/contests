/*
[arc110] B - Many 110
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

const string P = "110";

int N;
string T;

ll solve() {
    if (T == "00") return 0;
    if (T == "0" || T == "10" || T == "11") return 1e10;
    if (T == "1") return 2e10;
    if (T == "01") return 1e10 - 1;

    string t = T.substr(0, 3);
    int k;
    if (t == "110") {
        k = 0;
    } else if (t == "101") {
        k = 1;
    } else if (t == "011") {
        k = 2;
    } else {
        return 0;
    }
    REP(i, N - 3) {
        if (T[i + 3] != T[i]) return 0;
    }

    ll ans = (3e10 - N - k) / 3 + 1;
    return ans;
}

int main() {
    cin >> N;
    cin >> T;

    cout << solve() << endl;

    return 0;
}
