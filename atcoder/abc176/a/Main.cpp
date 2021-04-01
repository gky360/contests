/*
[abc176] A - Takoyaki
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

int N, X, T;

ll solve() { return (N + X - 1) / X * T; }

int main() {
    cin >> N >> X >> T;

    cout << solve() << endl;

    return 0;
}
