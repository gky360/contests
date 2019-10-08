/*
[tenka1-2019] D - Three Colors
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 300;
const int MAX_A = 300;
const int MAX_S = MAX_N * MAX_A;
const ll MOD = 998244353;

int N;
int a[MAX_N];
ll dp0[MAX_N + 1][MAX_S + 1];
ll dp1[MAX_N + 1][MAX_S + 1];

ll solve() {
    int S = accumulate(a, a + N, 0);
    ll pow3 = 1;
    for (int i = 0; i < N; i++) {
        (pow3 *= 3) %= MOD;
    }

    dp0[0][0] = 1;
    dp1[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= MAX_S; j++) {
            (dp0[i + 1][j] += dp0[i][j] * 2) %= MOD;
            (dp1[i + 1][j] += dp1[i][j]) %= MOD;
            if (j + a[i] <= MAX_S) {
                (dp0[i + 1][j + a[i]] += dp0[i][j]) %= MOD;
                (dp1[i + 1][j + a[i]] += dp1[i][j]) %= MOD;
            }
        }
    }

    ll c0 = 0;
    for (int j = (S + 1) / 2; j <= MAX_S; j++) {
        (c0 += dp0[N][j]) %= MOD;
    }
    ll c1 = (S % 2 == 0) ? dp1[N][S / 2] : 0;

    ll ans = (pow3 - 3 * c0 + 3 * c1 + 3 * MOD) % MOD;

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
