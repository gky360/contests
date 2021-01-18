/*
[agc044] A - Pay to Win
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

const ll INF = 1e18 + 7;

int T;
ll N;
int ABC[3], D;
map<ll, ll> m;
ll k[3] = {2, 3, 5};

ll f(ll n) {
    if (m.count(n)) return m[n];
    if (n == 0) return m[n] = 0;
    ll ret = min(1.0L * INF, 1.0L * n * D);
    for (int i = 0; i < 3; i++) {
        if (n / k[i] != n)
            ret = min(ret, (n - n / k[i] * k[i]) * D + ABC[i] + f(n / k[i]));
        if (n / k[i] + 1 != n)
            ret = min(ret, ((n / k[i] + 1) * k[i] - n) * D + ABC[i] +
                               f(n / k[i] + 1));
    }
    return m[n] = ret;
}

ll solve() {
    m.clear();

    ll ans = f(N);
    return ans;
}

int main() {
    cin >> T;
    REP(i, T) {
        cin >> N >> ABC[0] >> ABC[1] >> ABC[2] >> D;
        cout << solve() << endl;
    }

    return 0;
}
