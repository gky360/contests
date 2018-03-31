// AGC022
// A - Diverse Word

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int AZ = 26;

string s;

string solve() {
    string ans;
    if (s.length() < AZ) {
        vector<bool> used(AZ);
        for (char c : s) {
            used[c - 'a'] = true;
        }
        for (int i = 0; i < AZ; i++) {
            if (!used[i]) {
                ans = s + (char)('a' + i);
                break;
            }
        }
    } else {
        ans = s;
        next_permutation(ans.begin(), ans.end());
        if (ans < s) {
            return "-1";
        }
        for (int i = 0; i < AZ; i++) {
            if (ans[i] != s[i]) {
                ans = ans.substr(0, i + 1);
            }
        }
    }
    return ans;
}

int main() {
    cin >> s;

    cout << solve() << endl;

    return 0;
}
