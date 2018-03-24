// AtCoder Grand Contest 016
// A - Shrinking

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


string s;
int ans;

int main() {

    int span, idx, pre_idx;

    cin >> s;

    ans = s.length();
    for (char c = 'a'; c <= 'z'; c++) {
        span = 0;
        pre_idx = -1;
        while ((decltype(string::npos))(idx = s.find_first_of(c, pre_idx + 1)) != string::npos) {
            span = max(span, idx - pre_idx - 1);
            pre_idx = idx;
        }
        span = max(span, (int)s.length() - pre_idx - 1);
        ans = min(ans, span);
    }

    cout << ans << endl;

    return 0;

}



