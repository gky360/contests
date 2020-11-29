/*
[abc162] B - FizzBuzz Sum
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

ll solve() {
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 3 != 0 && i % 5 != 0) ans += i;
    }
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
