/*
[abc181] E - Transformable Teacher
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
const int MAX_M = 2e5;
const ll INF = 1e18;

int N, M;
ll H[MAX_N], W[MAX_M];

ll solve() {
    ll a[MAX_N / 2 + 1], b[MAX_N / 2 + 1];

    sort(H, H + N);

    a[0] = 0;
    for (int i = 0; 2 * i + 1 < N; i++) {
        a[i + 1] = a[i] + abs(H[2 * i] - H[2 * i + 1]);
    }
    b[0] = 0;
    for (int i = 0; 2 * i + 1 < N; i++) {
        b[i + 1] = b[i] + abs(H[2 * i + 1] - H[2 * i + 2]);
    }

    ll ans = INF;
    REP(i, M) {
        int x = lower_bound(H, H + N, W[i]) - H;
        ll ret = a[x / 2] + b[N / 2] - b[x / 2] + abs(W[i] - H[x - x % 2]);
        ans = min(ans, ret);
    }

    return ans;
}

int main() {
    cin >> N >> M;
    REP(i, N) cin >> H[i];
    REP(i, M) cin >> W[i];

    cout << solve() << endl;

    return 0;
}
