/*
[abc121] D - XOR World
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

ll A, B;

ll f(ll x) { return ((x + 1) / 2 % 2) ^ ((x & 1) ? 0 : x); }

ll solve() { return f(A - 1) ^ f(B); }

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
