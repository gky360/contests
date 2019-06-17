/*
[dp] F - LCS
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int M, N;
string s;
string t;

string solve() {
    vector<vector<int>> dp(M + 1, vector<int>(N + 1));
    vector<vector<int>> b(M + 1, vector<int>(N + 1));

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[(i - 1)][j - 1] + 1;
                b[i][j] = 2;
            } else if (dp[(i - 1)][j] > dp[i][j - 1]) {
                dp[i][j] = dp[(i - 1)][j];
                b[i][j] = 0;
            } else {
                dp[i][j] = dp[i][j - 1];
                b[i][j] = 1;
            }
        }
    }

    string ans;
    for (int i = M, j = N; i > 0 && j > 0;) {
        if (b[i][j] == 0) {
            i--;
        } else if (b[i][j] == 1) {
            j--;
        } else {
            ans.push_back(s[i - 1]);
            i--;
            j--;
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    cin >> s;
    cin >> t;
    M = s.length();
    N = t.length();

    cout << solve() << endl;

    return 0;
}
