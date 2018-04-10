// ARC087
// D - FT Robot

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_S = 8000;

string s;
int xy[2];

bool solve() {
    int t_cnt = 0, f_cnt = 0;
    vector<int> mv[2];
    for (char c : s) {
        if (c == 'T') {
            mv[t_cnt % 2].push_back(f_cnt);
            f_cnt = 0;
            t_cnt++;
        } else {
            f_cnt++;
        }
    }
    mv[t_cnt % 2].push_back(f_cnt);

    for (int k = 0; k <= 1; k++) {
        bool dp[2][2 * MAX_S + 1];
        memset(dp[0], 0, sizeof(dp[0]));
        dp[0][0 + MAX_S] = true;
        for (int j = 1; j <= (int)mv[k].size(); j++) {
            memset(dp[j % 2], 0, sizeof(dp[j % 2]));
            int d = mv[k][j - 1];
            for (int i = 0; i < 2 * MAX_S + 1; i++) {
                if (i + d < 2 * MAX_S + 1) {
                    dp[j % 2][i + d] = dp[j % 2][i + d] || dp[(j - 1) % 2][i];
                }
                if (i - d >= 0 && !(k == 0 && j == 1)) {
                    dp[j % 2][i - d] = dp[j % 2][i - d] || dp[(j - 1) % 2][i];
                }
            }
        }
        if (!dp[(int)mv[k].size() % 2][xy[k] + MAX_S]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> s;
    cin >> xy[0] >> xy[1];

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
