/*
[abc172] D - Sum of Divisors
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

ll N;

ll solve() {
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += (i + N / i * i) * (N / i) / 2;
    }
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
