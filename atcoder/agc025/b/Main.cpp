// AGC025
// B - RGB Coloring

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const ll MOD = 998244353;

int N, A, B;
ll K;
vector<ll> fact, inv_fact;

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

ll combi(ll a, ll b) {
    return (fact[a] * inv_fact[a - b] % MOD) * inv_fact[b] % MOD;
}

int main() {
    cin >> N >> A >> B >> K;

    fact.resize(N + 1);
    inv_fact.resize(N + 1);
    fact[0] = 1;
    inv_fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = mod_inv(fact[i], MOD);
    }

    ll ans = 0;
    for (ll x = 0; x <= N && x * A <= K; x++) {
        if ((K - x * A) % B != 0) {
            continue;
        }
        ll y = (K - x * A) / B;
        if (y > N) {
            continue;
        }
        ans += combi(N, x) * combi(N, y) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
