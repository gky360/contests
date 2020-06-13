/*
[abc144] C - Walk on Multiplication Table
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const ll INF = 1e17;

ll N;

ll solve() {
    ll ans = INF;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            ans = min(ans, i + N / i - 2);
        }
    }
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
