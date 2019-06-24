/*
[dp] R - Walk
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

const int MAX_N = 50;
const ll MOD = 1e9 + 7;

int N;
ll K;
ll a[MAX_N][MAX_N];
ll t[MAX_N][MAX_N];

void mul(ll x[MAX_N][MAX_N], ll y[MAX_N][MAX_N]) {
    ll z[MAX_N][MAX_N];
    memset(z, 0, sizeof(z));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                (z[i][j] += (x[i][k] * y[k][j]) % MOD) %= MOD;
            }
        }
    }

    memcpy(x, z, sizeof(z));
}

ll solve() {
    for (int i = 0; i < N; i++) {
        t[i][i] = 1;
    }

    for (ll k = K; k > 0; k = k >> 1) {
        if (k & 1LL) {
            mul(t, a);
        }
        mul(a, a);
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            (ans += t[i][j]) %= MOD;
        }
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}
