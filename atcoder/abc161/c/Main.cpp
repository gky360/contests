/*
[abc161] C - Replacing Integer
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

ll N, K;

ll solve() {
    ll x = N % K;

    ll ans = min(x, K - x);
    return ans;
}

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
