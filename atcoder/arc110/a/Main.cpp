/*
[arc110] A - Redundant Redundancy
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

int N;

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

ll solve() {
    ll ans = 1;
    REP(i, N - 1) ans = lcm(ans, i + 2);
    ans++;
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
