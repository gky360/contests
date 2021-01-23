/*
[abc169] B - Multiplication 2
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

const int MAX_N = 1e5;
const ll X = 1e18;

int N;
ll A[MAX_N];

ll solve() {
    ll ans = 1;
    if (any_of(A, A + N, [](ll a) { return a == 0; })) return 0;
    REP(i, N) {
        if (X / ans < A[i]) return -1;
        ans *= A[i];
        if (ans > X) return -1;
    }

    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
