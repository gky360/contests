/*
[abc148] C - Snack
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

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

int A, B;

ll solve() { return lcm(A, B); }

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
