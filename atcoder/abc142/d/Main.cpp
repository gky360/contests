/*
[abc142] D - Disjoint Set of Common Divisors
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e6;

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

ll A, B;

ll solve() {
    ll g = gcd(A, B);
    int ans = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (g % i == 0) {
            ans++;
        }
        while (g % i == 0) {
            g /= i;
        }
    }
    if (g > 1) {
        ans++;
    }

    return ans;
}

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
