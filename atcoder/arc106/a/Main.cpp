/*
[arc106] A - 106
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

void solve() {
    for (ll a = 1, p = 3; p <= N; a++, p *= 3) {
        for (ll b = 1, q = 5; q <= N; b++, q *= 5) {
            if (p + q == N) {
                cout << a << " " << b << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
    return;
}

int main() {
    cin >> N;

    solve();

    return 0;
}
