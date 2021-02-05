/*
[agc046] A - Takahashikun, The Strider
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

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll d = gcd(a, b);
    return a * b / d;
}

int X;

ll solve() {
    ll ans = lcm(X, 360) / X;
    return ans;
}

int main() {
    cin >> X;

    cout << solve() << endl;

    return 0;
}
