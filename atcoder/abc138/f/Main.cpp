/*
[abc138] F - Coincidence
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_D = 64;
const ll MOD = 1e9 + 7;

ll L, R;
ll memo[MAX_D][2][2][2];

ll f(int d, int m, int l, int r) {
    if (d == -1) {
        return m == 1;
    }
    if (memo[d][m][l][r] >= 0) {
        return memo[d][m][l][r];
    }

    ll ret = 0;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            if ((l && a < ((L >> d) & 1)) || (r && b > ((R >> d) & 1)) ||
                (a > b) || (!m && a != b)) {
                continue;
            }
            int nm = m || (a & b);
            int nl = l && (((L >> d) & 1) == a);
            int nr = r && (((R >> d) & 1) == b);
            (ret += f(d - 1, nm, nl, nr)) %= MOD;
        }
    }
    return memo[d][m][l][r] = ret;
}

ll solve() {
    memset(memo, -1, sizeof(memo));
    return f(MAX_D - 1, 0, 1, 1);
}

int main() {
    cin >> L >> R;

    cout << solve() << endl;

    return 0;
}
