/*
[abc127] E - Cell Distance
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const ll MOD = 1e9 + 7;

ll N, M;
ll K;

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

ll fac(int n) {
    ll ret = 1;
    for (int i = 2; i <= n; i++) {
        (ret *= i) %= MOD;
    }
    return ret;
}

ll solve() {
    ll c = (fac(N * M - 2) * mod_inv(fac(N * M - K) * fac(K - 2) % MOD, MOD)) %
           MOD;

    ll ans = 0;
    for (ll d = 1; d < N; d++) {
        ll a = ((((d * (N - d) % MOD) * (M * M % MOD)) % MOD) * c) % MOD;
        (ans += a) %= MOD;
    }
    for (ll d = 1; d < M; d++) {
        ll a = ((((d * (M - d) % MOD) * (N * N % MOD)) % MOD) * c) % MOD;
        (ans += a) %= MOD;
    }

    return ans;
}

int main() {
    cin >> N >> M >> K;

    cout << solve() << endl;

    return 0;
}
