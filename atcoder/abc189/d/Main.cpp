/*
[abc189] D - Logical Expression
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

const int MAX_N = 60;

int N;
string S[MAX_N];

ll solve() {
    ll x[2] = {1, 1};
    REP(i, N) {
        ll f = x[0], t = x[1];
        if (S[i] == "AND") {
            x[0] = 2 * f + t;
            x[1] = t;
        } else {
            x[0] = f;
            x[1] = 2 * t + f;
        }
    }

    ll ans = x[1];
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> S[i];

    cout << solve() << endl;

    return 0;
}
