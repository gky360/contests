/*
[arc111] A - Simple Math 2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

ll N, M;

ll mod_pow(ll a, ll n, ll m) {
    ll ret = 1;
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            (ret *= a) %= m;
        }
        (a *= a) %= m;
    }
    return ret;
}

ll solve() {
    ll ans = mod_pow(10, N, M * M) / M % M;
    return ans;
}

int main() {
    cin >> N >> M;

    cout << solve() << endl;

    return 0;
}
