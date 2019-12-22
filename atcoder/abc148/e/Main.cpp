/*
[abc148] E - Double Factorial
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

ll N;

ll solve() {
    if (N % 2 == 1) {
        return 0;
    }

    ll ans = 0;
    for (ll p = 10; p <= N; p *= 5) {
        ans += N / p;
    }

    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
