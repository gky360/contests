/*
[abc186] E - Throne
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

int T;
int N, S, K;

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

ll mod_inv(ll a, ll m) {
    ll u = 0, v = 1, mod = m;
    while (a != 0) {
        ll t = m / a;
        m -= t * a;
        u -= t * v;
        swap(a, m);
        swap(u, v);
    }
    return (u + mod) % mod;
}

ll solve() {
    int a = K, b = N - S, m = N;
    int d = gcd(gcd(a, b), m);
    a /= d, b /= d, m /= d;
    if (gcd(a, m) != 1) return -1;
    int ans = mod_inv(a, m) * b % m;
    return ans;
}

int main() {
    cin >> T;
    REP(i, T) {
        cin >> N >> S >> K;
        cout << solve() << endl;
    }

    return 0;
}
