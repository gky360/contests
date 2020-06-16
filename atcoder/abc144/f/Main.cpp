/*
[abc144] F - Fork in the Road
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 600;

int N, M;
vector<int> g[MAX_N];

double calc(int skip) {
    double dp[MAX_N];
    dp[N - 1] = 0;
    for (int i = N - 2; i >= 0; i--) {
        int s = g[i].size();
        dp[i] = 0;
        if (i == skip && s > 1) {
            int skip_j = -1;
            double max_dp_to = 0;
            for (int j = 0; j < s; j++) {
                if (dp[g[i][j]] > max_dp_to) {
                    max_dp_to = dp[g[i][j]];
                    skip_j = j;
                }
            }
            for (int j = 0; j < s; j++) {
                if (j == skip_j) continue;
                int to = g[i][j];
                dp[i] += (dp[to] + 1.0) / (s - 1);
            }
        } else {
            for (int to : g[i]) {
                dp[i] += (dp[to] + 1.0) / s;
            }
        }
    }
    return dp[0];
}

double solve() {
    double ans = N;
    for (int i = 0; i < N; i++) {
        ans = min(ans, calc(i));
    }
    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        g[s - 1].push_back(t - 1);
    }

    cout << fixed << setprecision(10) << solve() << endl;

    return 0;
}
