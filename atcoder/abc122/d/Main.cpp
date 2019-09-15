/*
[abc122] D - We Like AGC
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 100;
const ll MOD = 1e9 + 7;
// const char cs[4] = {'A', 'C', 'G', 'T'};

int N;
ll dp[MAX_N + 4][4][4][4];

vector<int> to_arr(int p) {
    return {p & 3, (p >> 2) & 3, (p >> 4) & 3, (p >> 6) & 3};
}

bool is_ok(int p) {
    vector<int> s = to_arr(p);
    for (int i = 0; i < 4; i++) {
        if (i > 0) {
            swap(s[i - 1], s[i]);
        }
        for (int j = 0; j < 2; j++) {
            if (s[j] == 0 && s[j + 1] == 2 && s[j + 2] == 1) {
                return false;
            }
        }
        if (i > 0) {
            swap(s[i - 1], s[i]);
        }
    }

    return true;
}

ll solve() {
    dp[0][3][3][3] = 1;
    for (int i = 1; i < N + 4; i++) {
        for (int p = 0; p < 256; p++) {
            if (is_ok(p)) {
                vector<int> s = to_arr(p);
                (dp[i][s[1]][s[2]][s[3]] += dp[i - 1][s[0]][s[1]][s[2]]) %= MOD;
            }
        }
    }

    return dp[N + 3][3][3][3];
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
