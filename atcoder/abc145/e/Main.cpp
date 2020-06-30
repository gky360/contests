/*
[abc145] E - All-you-can-eat
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 3000;
const int MAX_T = 3000;

int N, T;
pii AB[MAX_N];
int dp[MAX_N][MAX_T];

ll solve() {
    sort(AB, AB + N);

    for (int i = 1; i < N; i++) {
        int a = AB[i - 1].first, b = AB[i - 1].second;
        for (int t = 1; t <= T - 1; t++) {
            if (t - a >= 0) {
                dp[i][t] = max(dp[i - 1][t], dp[i - 1][t - a] + b);
            } else {
                dp[i][t] = dp[i - 1][t];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[i][T - 1] + AB[i].second);
    }

    return ans;
}

int main() {
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> AB[i].first >> AB[i].second;
    }

    cout << solve() << endl;

    return 0;
}
