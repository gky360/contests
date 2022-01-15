/*
[arc112] B - -- - B
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

ll B, C;

ll solve() {
    ll p = B - C / 2, q = B + (C - 2) / 2, r = -B - (C - 1) / 2,
       s = -B + (C - 1) / 2;
    return q - p + 1 + s - r + 1 - max(0LL, min(q, s) - max(p, r) + 1);
}

int main() {
    cin >> B >> C;

    cout << solve() << endl;

    return 0;
}
