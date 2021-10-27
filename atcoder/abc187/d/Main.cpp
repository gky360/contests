/*
[abc187] D - Choose Me
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
ll A[MAX_N], B[MAX_N];

ll solve() {
    ll d[MAX_N];
    ll D = 0;
    REP(i, N) {
        D -= A[i];
        d[i] = 2 * A[i] + B[i];
    }
    sort(d, d + N);
    ll ans = 0;
    for (int i = 0; i < N && D <= 0; D += d[N - 1 - i], i++) ans++;

    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i] >> B[i];

    cout << solve() << endl;

    return 0;
}
