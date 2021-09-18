/*
[arc109] C - Large RPS Tournament
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

const int MAX_N = 100;
const int MAX_K = 100;

int n, k;
string S;
int p[MAX_K + 1];
char dp[MAX_N][MAX_K + 1];

char win(char a, char b) {
    if (a == b) return a;
    if ((a == 'R' && b == 'S') || (a == 'P' && b == 'R') ||
        (a == 'S' && b == 'P'))
        return a;
    return b;
}

char solve() {
    for (int i = 0, pp = 1; i <= k; i++, (pp *= 2) %= n) p[i] = pp;

    REP(i, n) dp[i][0] = S[i];
    REP(j, k) REP(i, n) { dp[i][j + 1] = win(dp[i][j], dp[(i + p[j]) % n][j]); }

    char ans = dp[0][k];
    return ans;
}

int main() {
    cin >> n >> k;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
