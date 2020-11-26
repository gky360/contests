/*
[abc161] F - Division or Subtraction
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

ll N;

vector<ll> divisors(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

ll solve() {
    ll ans = divisors(N - 1).size() - 1;
    for (ll d : divisors(N)) {
        if (d == 1) continue;
        ll n = N;
        while (n % d == 0) {
            n /= d;
        }
        if (n % d == 1) ans++;
    }
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
