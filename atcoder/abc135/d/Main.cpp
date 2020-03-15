/*
[abc135] D - Digits Parade
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int M = 13;
const int MOD = 1e9 + 7;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(const gf x) const { return gf((n + x.n) % MOD); }
    gf& operator+=(const gf x) { return *this = (*this + x); }
};

int N;
string S;
gf dp[MAX_N + 1][M];

ll solve() {
    dp[0][0] = 1;
    for (int n = 0; n < N; n++) {
        for (int d = 0; d <= 9; d++) {
            if (S[n] == '?' || S[n] == '0' + d) {
                for (int m = 0; m < M; m++) {
                    dp[n + 1][(m * 10 + d) % M] += dp[n][m];
                }
            }
        }
    }

    return dp[N][5].n;
}

int main() {
    cin >> S;
    N = S.length();

    cout << solve() << endl;

    return 0;
}
