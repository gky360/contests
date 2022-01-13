/*
[arc112] A - B = C
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

const int MAX_T = 2e4;

int T;
int L[MAX_T], R[MAX_T];

void solve() {
    REP(i, T) {
        ll p = L[i], q = R[i] - L[i] + 1;
        if (p > q) {
            cout << 0 << endl;
        } else {
            cout << q * (q - p + 1) - (p + q) * (q - p + 1) / 2 << endl;
        }
    }
}

int main() {
    cin >> T;
    REP(i, T) { cin >> L[i] >> R[i]; }
    solve();

    return 0;
}
