/*
[abc129] E - Sum Equals Xor
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 100001;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
};

bitset<MAX_N> L;
gf dp[MAX_N + 1][2];

ll solve() {
    dp[MAX_N][0] = 1;
    for (int i = MAX_N; i > 0; i--) {
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int j = 0; j <= (smaller ? 1 : L[i - 1]); j++) {
                dp[i - 1][smaller || j < L[i - 1]] += dp[i][smaller] * (j + 1);
            }
        }
    }
    gf ans = dp[0][0] + dp[0][1];
    return ans.n;
}

int main() {
    cin >> L;

    cout << solve() << endl;

    return 0;
}
