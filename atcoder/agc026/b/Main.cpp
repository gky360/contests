/*
[agc026] B - rng_10s
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

ll solve(ll a, ll b, ll c, ll d) {
    if (a < b) {
        return false;
    }
    if (d < b) {
        return false;
    }
    if (c >= b) {
        return true;
    }
    ll g = gcd(b, d);
    return (b - g + (a % g) <= c);
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (solve(a, b, c, d) ? "Yes" : "No") << endl;
    }

    return 0;
}
