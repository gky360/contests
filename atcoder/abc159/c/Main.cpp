/*
[abc159] C - Maximum Volume
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

double L;

double solve() {
    double r = L / 3;
    return r * r * r;
}

int main() {
    cin >> L;

    cout << fixed << setprecision(12) << solve() << endl;

    return 0;
}
