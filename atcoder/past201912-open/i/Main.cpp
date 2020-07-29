/*
[past201912-open] I - 部品調達 / Procurement
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 10;
const int MAX_M = 1000;
const ll INF = 1e18;

int N, M;
string S[MAX_M];
int C[MAX_M];
ll dp[1 << MAX_N];

ll solve() {
    int sp[MAX_M];
    for (int j = 0; j < M; j++) {
        sp[j] = 0;
        for (int i = 0; i < N; i++) {
            if (S[j][i] == 'Y') {
                sp[j] |= (1 << i);
            }
        }
    }

    for (int pat = 0; pat < (1 << N); pat++) {
        fill(dp, dp + (1 << N), INF);
    }
    dp[0] = 0;

    for (int j = 0; j < M; j++) {
        for (int pat = 0; pat < (1 << N); pat++) {
            dp[pat | sp[j]] = min(dp[pat | sp[j]], dp[pat] + C[j]);
        }
    }

    ll ans = dp[(1 << N) - 1];
    if (ans >= INF) {
        ans = -1;
    }
    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> S[i] >> C[i];
    }

    cout << solve() << endl;

    return 0;
}
