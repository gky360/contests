/*
[abc174] F - Range Set Query
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

const int MAX_N = 5e5;
const int MAX_Q = 5e5;

template <typename T>
class BIT {
public:
    vector<T> b;
    BIT(int n) : b(n + 1) {}
    T sum(int i) {  // i : [0, n], returns sum of [0, i)
        T s = 0;
        for (; i > 0; i -= i & -i) s += b[i];
        return s;
    }
    void add(int i, T x) {  // i : [0, n)
        for (i += 1; i < (int)b.size(); i += i & -i) b[i] += x;
    }
};

int N, Q;
int c[MAX_N];
pair<pii, int> rl[MAX_Q];
vector<int> cp[MAX_N];
int ans[MAX_Q];

void solve() {
    BIT<int> bit(N);

    REP(i, N) cp[c[i]].push_back(i);
    REP(i, N) {
        if (!cp[i].empty()) bit.add(cp[i].back(), 1);
    }

    sort(rl, rl + Q, greater<pair<pii, int>>());
    int idx = N - 1;
    REP(q, Q) {
        int l = rl[q].first.second, r = rl[q].first.first, qi = rl[q].second;
        for (; idx > r; idx--) {
            cp[c[idx]].pop_back();
            if (!cp[c[idx]].empty()) bit.add(cp[c[idx]].back(), 1);
        }
        ans[qi] = bit.sum(r + 1) - bit.sum(l);
    }

    REP(i, Q) cout << ans[i] << endl;
}

int main() {
    cin >> N >> Q;
    REP(i, N) cin >> c[i], c[i]--;
    REP(i, Q) {
        cin >> rl[i].first.second >> rl[i].first.first;
        rl[i].second = i;
        rl[i].first.first--, rl[i].first.second--;
    }

    solve();

    return 0;
}
