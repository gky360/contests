/*
[abc144] D - Water Bottle
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int a, b, x;

double solve() {
    double th = (x <= a * a * b * 0.5)
                    ? atan(a * b * b * 1.0 / (2.0 * x))
                    : atan(2.0 * (a * a * b - x) / (a * a * a));
    return th * 180.0 / M_PI;
}

int main() {
    cin >> a >> b >> x;

    cout << fixed << setprecision(10) << solve() << endl;

    return 0;
}
