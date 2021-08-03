/*
[abc181] D - Hachi
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

map<int, int> calc(string s) {
    map<int, int> ret;
    while (!s.empty()) {
        ret[s.back() - '0']++;
        s.pop_back();
    }
    return ret;
}

bool solve() {
    auto cnt = calc(S);
    for (int n = 0; n < 1000; n += 8) {
        string s = to_string(n);
        if (min(3ul, S.length()) > s.length()) continue;
        auto t = calc(s);
        bool can = true;
        for (auto [k, c] : t) {
            if (cnt[k] < c) can = false;
        }
        if (can) return true;
    }
    return false;
}

int main() {
    cin >> S;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
