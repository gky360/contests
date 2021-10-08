/*
[past202012-open] N - Travel Agency
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
pii L[MAX_N - 1], R[MAX_N - 1];
pair<pii, int> ABQ[MAX_Q];
int ans[MAX_Q];

void solve() {
    sort(L, L + N - 1);
    sort(R, R + N - 1);
    sort(ABQ, ABQ + Q);

    set<int> s;
    REP(i, N + 1) s.insert(i);

    int li = 0, ri = 0;
    REP(i, Q) {
        int a = ABQ[i].first.first, b = ABQ[i].first.second, q = ABQ[i].second;
        for (; li < N - 1 && L[li].first <= a; li++) s.erase(L[li].second);
        for (; ri < N - 1 && R[ri].first < a; ri++) s.insert(R[ri].second);
        auto iter = s.lower_bound(b);
        int rn = *iter;
        int ln = *(--iter) + 1;
        ans[q] = rn - ln + 1;
    }
}

int main() {
    cin >> N >> Q;
    REP(i, N - 1)
    cin >> L[i].first >> R[i].first, L[i].second = i + 1, R[i].second = i + 1;
    REP(q, Q)
    cin >> ABQ[q].first.first >> ABQ[q].first.second, ABQ[q].second = q;

    solve();

    REP(q, Q) cout << ans[q] << endl;

    return 0;
}
