/*
[arc105] B - MAX-=min
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

int N;
set<int> s;

ll solve() {
    while (s.size() > 1) {
        int r = *s.rbegin(), l = *s.begin();
        s.erase(r);
        int r2 = *s.begin();
        int p = (r - r2 + l - 1) / l;
        s.insert(r - p * l);
    }
    ll ans = *s.begin();
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) {
        int a;
        cin >> a;
        s.insert(a);
    }

    cout << solve() << endl;

    return 0;
}
