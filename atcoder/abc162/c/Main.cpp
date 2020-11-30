/*
[abc162] C - Sum of gcd of Tuples (Easy)
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

int K;

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

ll solve() {
    ll ans = 0;
    REP(a, K)
    REP(b, K)
    REP(c, K) ans += gcd(gcd(a + 1, b + 1), c + 1);
    return ans;
}

int main() {
    cin >> K;

    cout << solve() << endl;

    return 0;
}
