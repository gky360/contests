/*
[abc184] D - increment of coins
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

const int MAX_A = 100;

int A, B, C;
DD dp[MAX_A + 1][MAX_A + 1][MAX_A + 1];

DD calc(int a, int b, int c) {
    if (dp[a][b][c] >= 0) return dp[a][b][c];
    if (a == MAX_A || b == MAX_A || c == MAX_A) return dp[a][b][c] = 0.0;
    DD s = a + b + c;
    return dp[a][b][c] = a / s * (calc(a + 1, b, c) + 1) +
                         b / s * (calc(a, b + 1, c) + 1) +
                         c / s * (calc(a, b, c + 1) + 1);
}

DD solve() {
    REP(i, MAX_A + 1) REP(j, MAX_A + 1) REP(k, MAX_A + 1) dp[i][j][k] = -1.0;

    DD ans = calc(A, B, C);
    return ans;
}

int main() {
    cin >> A >> B >> C;

    cout << fixed << setprecision(9) << solve() << endl;

    return 0;
}
