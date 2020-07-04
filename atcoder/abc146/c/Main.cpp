/*
[abc146] C - Buy an Integer
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const ll MAX_N = 1e9;

ll A, B, X;

ll d(ll n) {
    int ret;
    for (ret = 0; n > 0; n /= 10) {
        ret++;
    }
    return ret;
}

bool can(ll n) { return A * n + B * d(n) <= X; }

ll solve() {
    ll ok = 0, ng = MAX_N + 1;
    while (ng - ok > 1) {
        ll m = (ng + ok) / 2;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }

    return ok;
}

int main() {
    cin >> A >> B >> X;

    cout << solve() << endl;

    return 0;
}
