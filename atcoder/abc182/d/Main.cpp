/*
[abc182] D - Wandering
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

const int MAX_N = 200000;

int N;
ll A[MAX_N];

ll solve() {
    ll s[MAX_N + 1], ms[MAX_N + 1];
    s[0] = ms[0] = 0;
    REP(i, N) {
        s[i + 1] = s[i] + A[i];
        ms[i + 1] = max(ms[i], s[i + 1]);
    }

    ll ans = 0;
    ll x = 0;
    REP(i, N) {
        ans = max(ans, x + ms[i + 1]);
        x += s[i + 1];
    }
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
