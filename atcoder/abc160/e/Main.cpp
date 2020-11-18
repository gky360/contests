/*
[abc160] E - Red and Green Apples
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

const int MAX_A = 1e5;

int X, Y, A, B, C;
int p[MAX_A], q[MAX_A], r[MAX_A];

ll solve() {
    sort(p, p + A, greater<int>());
    sort(q, q + B, greater<int>());
    vector<int> s;
    REP(i, X) s.push_back(p[i]);
    REP(i, Y) s.push_back(q[i]);
    REP(i, C) s.push_back(r[i]);
    sort(ALL(s), greater<int>());
    ll ans = 0;
    REP(i, X + Y) ans += s[i];
    return ans;
}

int main() {
    cin >> X >> Y >> A >> B >> C;
    REP(i, A) cin >> p[i];
    REP(i, B) cin >> q[i];
    REP(i, C) cin >> r[i];

    cout << solve() << endl;

    return 0;
}
