/*
[past202010-open] L - マンションの改築
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
ll h[MAX_N];
int t[MAX_Q];
ll v[MAX_Q][2];

ll calc_d(int i) {
    assert(0 <= i && i < N);
    return (h[i] - h[i + 1]) * (i % 2 * 2 - 1);
}

void solve() {
    map<ll, int> m;
    REP(i, N - 1) {
        m[calc_d(i)]++;  // k - g
    }

    ll d = 0;
    REP(q, Q) {
        if (t[q] == 3) {
            int i = v[q][0] - 1;
            if (i - 1 >= 0) m[calc_d(i - 1)]--;
            m[calc_d(i)]--;
            h[i] += v[q][1];
            if (i - 1 >= 0) m[calc_d(i - 1)]++;
            m[calc_d(i)]++;
        } else {
            d += v[q][0] * (3 - t[q] * 2);
        }
        cout << m[d] << endl;
    }
}

int main() {
    cin >> N >> Q;
    REP(i, N) cin >> h[i];
    REP(q, Q) {
        cin >> t[q];
        cin >> v[q][0];
        if (t[q] == 3) cin >> v[q][1];
    }

    solve();

    return 0;
}
