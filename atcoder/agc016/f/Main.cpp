/*
[agc016] F - Games on DAG
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 15;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n < 0 ? n % MOD + MOD : n % MOD) {}
    gf operator+(gf x) { return gf((n + x.n) % MOD); }
    gf operator-(gf x) { return gf((n - x.n + MOD) % MOD); }
    gf operator*(gf x) { return gf((1LL * n * x.n) % MOD); }
    gf& operator+=(gf x) { return *this = (*this + x); }
    gf& operator-=(gf x) { return *this = (*this - x); }
    gf& operator*=(gf x) { return *this = (*this * x); }
};

int N, M;
int E[MAX_N];
gf dp[1 << MAX_N];

int solve() {
    int full = (1 << N) - 1;
    dp[0] = 1;
    for (int s = 0; s < full; s++) {
        int ut = full ^ s;
        for (int t = ut; t > 0; t = (t - 1) & ut) {
            int u = ut ^ t;
            if ((t & 3) == 3) continue;
            gf m = 1;
            for (int i = 0; i < N; i++) {
                if (t & (1 << i)) {
                    m *= 1 << __builtin_popcount(E[i] & u);
                } else if (u & (1 << i)) {
                    m *= (1 << __builtin_popcount(E[i] & t)) - 1;
                }
            }
            dp[s | t] += m * dp[s];
        }
    }

    int ans = dp[full].n;
    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        E[x] |= 1 << y;
    }

    cout << solve() << endl;

    return 0;
}
