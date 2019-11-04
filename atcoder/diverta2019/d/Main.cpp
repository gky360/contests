/*
[diverta2019] D - DivRem Number
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

ll N;
vector<pli> fac;

ll solve() {
    vector<ll> divs;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            divs.push_back(i);
            if (i * i != N) {
                divs.push_back(N / i);
            }
        }
    }

    ll ans = 0;
    for (ll d : divs) {
        ll m = d - 1;
        if (m > 0 && (N / m == N % m)) {
            ans += m;
        }
    }

    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
