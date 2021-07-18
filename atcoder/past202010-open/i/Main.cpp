/*
[past202010-open] I - ピザ
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
const ll INF = 1e18;

int N;
ll a[MAX_N];

ll solve() {
    ll s = 0;
    REP(i, N) s += a[i];

    ll ans = INF;
    ll t = 0;
    int j = 0;
    REP(i, N) {
        for (; s - 2 * t > 0; j++) {
            ans = min(ans, abs(s - 2 * t));
            t += a[j % N];
        }
        ans = min(ans, abs(s - 2 * t));
        t -= a[i];
    }

    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> a[i];

    cout << solve() << endl;

    return 0;
}
