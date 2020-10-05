/*
[abc156] B - Digits
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N, K;

ll solve() {
    ll ans = 0;
    for (; N > 0; N /= K) {
        ans++;
    }
    return ans;
}

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
