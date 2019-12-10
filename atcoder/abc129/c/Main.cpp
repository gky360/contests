/*
[abc129] C - Typical Stairs
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int MAX_M = MAX_N - 1;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
};

int N, M;
bool broken[MAX_N + 1];
gf dp[MAX_N + 1];

ll solve() {
    dp[0] = 1;
    if (!broken[1]) {
        dp[1] = 1;
    }
    for (int i = 2; i <= N; i++) {
        if (!broken[i]) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    return dp[N].n;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        broken[a] = true;
    }

    cout << solve() << endl;

    return 0;
}
