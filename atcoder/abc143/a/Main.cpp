/*
[abc143] A - Curtain
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int A, B;

ll solve() {
    ll ans = max(0, A - 2 * B);
    return ans;
}

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
