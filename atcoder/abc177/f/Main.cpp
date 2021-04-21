/*
[abc177] F - I hate Shortest Path Problem
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

const int MAX_H = 2e5;

int H, W;
int A[MAX_H], B[MAX_H];

void solve() {
    set<pii> s;
    multiset<int> m;
    REP(i, W) {
        s.insert({i, i});
        m.insert(0);
    }

    REP(j, H) {
        int last_l = -1, last_r = -1;
        while (true) {
            auto iter = s.lower_bound(pii(A[j], 0));
            if (iter == s.end() || *iter > pii(B[j], W)) {
                break;
            }
            auto [r, l] = *iter;
            s.erase(iter);
            m.erase(m.find(r - l));
            r = B[j] + 1;
            if (r < W) {
                last_l = l, last_r = r;
            }
        }
        if (last_l != -1) {
            s.insert(pii(last_r, last_l));
            m.insert(last_r - last_l);
        }

        int ans = m.size() > 0 ? j + 1 + *m.begin() : -1;
        cout << ans << endl;
    }
}

int main() {
    cin >> H >> W;
    REP(i, H) cin >> A[i] >> B[i], A[i]--, B[i]--;

    solve();

    return 0;
}
