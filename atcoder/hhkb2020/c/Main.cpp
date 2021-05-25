/*
[hhkb2020] C - Neq Min
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
int p[MAX_N];

void solve() {
    set<int> s;
    REP(i, N + 1) s.insert(i);

    REP(i, N) {
        s.erase(p[i]);
        cout << *s.begin() << endl;
    }
}

int main() {
    cin >> N;
    REP(i, N) cin >> p[i];

    solve();

    return 0;
}
