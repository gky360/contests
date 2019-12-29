/*
[abc130] E - Common Subsequence
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 2e3;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(const gf x) const { return gf((n + x.n) % MOD); }
    gf operator-(const gf x) const { return gf((n - x.n + MOD) % MOD); }
};

int N, M;
int s[MAX_N], t[MAX_N];
gf dp[MAX_N + 1][MAX_N + 1], sum[MAX_N + 1][MAX_N + 1];

ll solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = sum[i - 1][j - 1] + 1;
            }
            sum[i][j] =
                sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + dp[i][j];
        }
    }

    gf ans = sum[N][M] + 1;
    return ans.n;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    for (int j = 0; j < M; j++) {
        cin >> t[j];
    }

    cout << solve() << endl;

    return 0;
}
