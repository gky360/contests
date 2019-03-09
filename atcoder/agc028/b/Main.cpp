/*
[agc028] B - Removing Blocks
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

const int MAX_N = 100000;
const ll MOD = 1e9 + 7;

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

int N;
ll a[MAX_N];
ll sinv[MAX_N + 1];

ll solve() {
    sinv[0] = 0;
    for (int i = 1; i <= N; i++) {
        sinv[i] = (sinv[i - 1] + mod_inv(i, MOD)) % MOD;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        (ans += ((sinv[N - i] + sinv[i + 1] - 1) * a[i]) % MOD) %= MOD;
    }
    for (int i = 1; i <= N; i++) {
        (ans *= i) %= MOD;
    }

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
