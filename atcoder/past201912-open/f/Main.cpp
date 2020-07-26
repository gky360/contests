/*
[past201912-open] F - DoubleCamelCase Sort
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string S;

bool is_cap(char c) { return c <= 'Z'; }

string str_tolower(string s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return tolower(c); });
    return s;
}

string solve() {
    vector<string> ss;

    int pre = 0;
    for (int i = 1; i < (int)S.length(); i++) {
        if (is_cap(S[i])) {
            i++;
            string s = S.substr(pre, i - pre);
            ss.push_back(s);
            pre = i;
        }
    }
    sort(ALL(ss), [](string &s0, string &s1) {
        return str_tolower(s0) < str_tolower(s1);
    });

    string ans;
    for (string &s : ss) {
        ans += s;
    }

    return ans;
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
