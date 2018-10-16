/*
[abc110] D - Factorization
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
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

const int MAX_N = 100000;
const int MAX_SQRT_M = 100000;
const int MAX_FACT_N = MAX_N + 100;
const ll MOD = 1e9 + 7;

int N, M;
ll fact[MAX_FACT_N], fact_inv[MAX_FACT_N];

ll solve() {
    fact[0] = 1;
    fact_inv[0] = 1;
    for (int i = 1; i < MAX_FACT_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        fact_inv[i] = mod_inv(fact[i], MOD);
    }

    map<int, int> pf;
    bool is_prime[MAX_SQRT_M];
    fill(is_prime, is_prime + MAX_SQRT_M, true);

    int remain = M;
    for (int i = 2; 1LL * i * i <= M; i++) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = 2 * i; 1LL * j * j <= M; j += i) {
            is_prime[j] = false;
        }
        for (; remain > 1 && remain % i == 0; remain /= i) {
            pf[i]++;
        }
    }
    if (remain > 1) {
        pf[remain] = 1;
    }

    ll ans = 1;
    for (auto& kv : pf) {
        int a = kv.second;
        ll c = ((fact[N - 1 + a] * fact_inv[a]) % MOD) * fact_inv[N - 1] % MOD;
        (ans *= c) %= MOD;
    }

    return ans;
}

int main() {
    cin >> N >> M;

    cout << solve() << endl;

    return 0;
}
