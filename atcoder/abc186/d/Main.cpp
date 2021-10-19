/*
[abc186] D - Sum of difference
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
ll A[MAX_N], s[MAX_N + 1];

ll solve() {
    sort(A, A + N);
    REP(i, N) s[i + 1] = s[i] + A[i];

    ll ans = 0;
    REP(i, N) ans += s[N] - s[i + 1] - (N - i - 1) * A[i];
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
