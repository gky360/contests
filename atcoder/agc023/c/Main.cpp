// AGC023
// C - Painting Machines

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 1000000;
const ll MOD = 1e9 + 7;

int N;
ll fact[MAX_N + 1];
ll fact_inv[MAX_N + 1];

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

void calc_fact() {
    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        fact_inv[i] = mod_inv(fact[i], MOD);
    }
}

ll solve() {
    calc_fact();

    ll ans = 0;
    ll prev_cnt = 0;
    for (int k = (N + 1) / 2; k <= N - 1; k++) {
        ll cnt = fact[k - 1];
        (cnt *= fact_inv[N - 1 - k]) %= MOD;
        (cnt *= fact_inv[2 * k - N]) %= MOD;
        (cnt *= fact[k]) %= MOD;
        (cnt *= fact[N - 1 - k]) %= MOD;
        (ans += k * (cnt - prev_cnt + MOD)) %= MOD;
        prev_cnt = cnt;
    }
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
