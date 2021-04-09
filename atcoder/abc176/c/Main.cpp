/*
[abc176] C - Step
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

const int MAX_N = 2e5;

int N;
ll A[MAX_N];

ll solve() {
    ll mx = 0;
    ll ans = 0;
    REP(i, N) {
        if (A[i] < mx) {
            ans += mx - A[i];
        } else {
            mx = A[i];
        }
    }
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
