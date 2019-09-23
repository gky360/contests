/*
[exawizards2019] D - Modulo Operations
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 200;
const int MAX_X = 1e5;
const ll MOD = 1e9 + 7;

int N, X;
int S[MAX_N];
ll dp[MAX_N + 1][MAX_X + 1];

ll fact(int n) {
    ll ret = 1;
    for (int i = 2; i <= n; i++) {
        (ret *= i) %= MOD;
    }

    return ret;
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
    ll d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}

ll mod_inv(ll a, ll m) {
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x) % m;
}

ll solve() {
    sort(S, S + N, greater<int>());

    dp[0][X] = fact(N);
    for (int i = 0; i < N; i++) {
        ll inv = mod_inv(N - i, MOD);
        for (int j = 0; j <= X; j++) {
            ll p = (dp[i][j] * inv) % MOD;
            ll q = (p * (N - i - 1)) % MOD;
            (dp[i + 1][j % S[i]] += p) %= MOD;
            (dp[i + 1][j] += q) %= MOD;
        }
    }

    ll ans = 0;
    for (int j = 0; j <= X; j++) {
        (ans += j * dp[N][j]) %= MOD;
    }

    return ans;
}

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    cout << solve() << endl;

    return 0;
}
