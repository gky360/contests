/*
[abc179] F - Simplified Reversi
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
const int MAX_Q = 2e5;

int N, Q;
int t[MAX_Q], x[MAX_Q];

ll solve() {
    int h = N - 1, w = N - 1;
    int a[MAX_N], b[MAX_N];

    REP(i, N) a[i] = b[i] = N - 1;

    ll ans = ll(N - 2) * (N - 2);
    REP(q, Q) {
        if (t[q] == 1) {
            if (x[q] < w) {
                for (int i = x[q]; i < w; i++) b[i] = h;
                w = x[q];
            }
            ans -= b[x[q]] - 1;
        } else {
            if (x[q] < h) {
                for (int i = x[q]; i < h; i++) a[i] = w;
                h = x[q];
            }
            ans -= a[x[q]] - 1;
        }
    }

    return ans;
}

int main() {
    cin >> N >> Q;
    REP(i, Q) cin >> t[i] >> x[i], x[i]--;

    cout << solve() << endl;

    return 0;
}
