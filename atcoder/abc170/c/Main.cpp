/*
[abc170] C - Forbidden List
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

const int MAX_N = 100;

int X, N;
int p[MAX_N];

ll solve() {
    set<int> s;
    REP(i, N) s.insert(p[i]);
    REP(i, 101) {
        if (s.count(X - i) == 0) return X - i;
        if (s.count(X + i) == 0) return X + i;
    }
    return -1;
}

int main() {
    cin >> X >> N;
    REP(i, N) cin >> p[i];

    cout << solve() << endl;

    return 0;
}
