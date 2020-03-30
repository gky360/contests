/*
[agc037] A - Dividing a String
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;

int N;
string S;
int dp[MAX_N + 1];

ll solve() {
    if (N == 1) {
        return 1;
    }

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = S[0] == S[1] ? 1 : 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = (S[i - 1] == S[i - 2]) ? dp[i - 3] + 2 : dp[i - 1] + 1;
    }

    return dp[N];
}

int main() {
    cin >> S;
    N = S.length();

    cout << solve() << endl;

    return 0;
}
