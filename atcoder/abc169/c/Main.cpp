/*
[abc169] C - Multiplication 3
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

const double EPS = 1e-8;

ll A;
double B;

ll solve() {
    ll ans = A * (int)(B * 100 + EPS) / 100;
    return ans;
}

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
