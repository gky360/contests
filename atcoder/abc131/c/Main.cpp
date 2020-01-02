/*
[abc131] C - Anti-Division
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

ll A, B, C, D;

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

ll calc(ll x) { return x / C + x / D - x / lcm(C, D); }

ll solve() {
    ll ans = B - A + 1 - (calc(B) - calc(A - 1));
    return ans;
}

int main() {
    cin >> A >> B >> C >> D;

    cout << solve() << endl;

    return 0;
}
