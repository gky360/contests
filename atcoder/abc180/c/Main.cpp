/*
[abc180] C - Cream puff
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
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

void solve() {
    vector<ll> divs = divisors(N);
    sort(ALL(divs));

    for (ll n : divs) {
        cout << n << endl;
    }
}

int main() {
    cin >> N;

    solve();

    return 0;
}
