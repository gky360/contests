/*
[agc031] B - Reversi
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 2e5;
const int MAX_C = 2e5;
const ll MOD = 1e9 + 7;

int N;
int C[MAX_N];
ll dp[MAX_N];

ll solve() {
    int last[MAX_C];
    memset(last, -1, sizeof(last));
    last[C[0]] = 0;
    dp[0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1];
        if (0 <= last[C[i]] && last[C[i]] < i - 1) {
            (dp[i] += dp[last[C[i]]]) %= MOD;
        }
        last[C[i]] = i;
    }

    return dp[N - 1];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
    }

    cout << solve() << endl;

    return 0;
}
