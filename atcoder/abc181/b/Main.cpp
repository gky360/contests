/*
[abc181] B - Trapezoid Sum
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

int N;
int A[MAX_N], B[MAX_N];

ll solve() {
    ll ans = 0;
    REP(i, N) ans += (A[i] + B[i]) * (B[i] - A[i] + 1LL) / 2LL;
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i] >> B[i];

    cout << solve() << endl;

    return 0;
}
