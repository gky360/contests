/*
[abc132] F - Small Products
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_R = 1e5;
const int MAX_K = 100;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(const gf x) const { return gf((n + x.n) % MOD); }
    gf operator*(const gf x) const { return gf((1LL * n * x.n) % MOD); }
};

int N, K;
gf dp[MAX_K + 1][MAX_R];
vector<int> t;

ll solve() {
    for (int i = 1; i * i <= N; i++) {
        t.push_back(i);
        if (N / i != i) {
            t.push_back(N / i);
        }
    }
    sort(t.begin(), t.end(), greater<int>());
    int T = t.size();
    t.push_back(0);

    for (int i = 1; i <= T; i++) {
        dp[0][i] = 1;
    }
    for (int k = 1; k <= K; k++) {
        for (int i = 1; i <= T; i++) {
            dp[k][i] =
                dp[k][i - 1] + dp[k - 1][T - i + 1] * (t[T - i] - t[T - i + 1]);
        }
    }

    return dp[K][T].n;
}

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
