/*
[abc168] C - : (Colon)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

double A, B, H, M;

double solve() {
    double al = 2.0 * M_PI * (H * 60 + M) / 720.0;
    double be = 2.0 * M_PI * M / 60.0;
    double th = abs(al - be);

    cerr << al << ", " << be << endl;

    double ans = sqrt(A * A + B * B - 2 * A * B * cos(th));
    return ans;
}

int main() {
    cin >> A >> B >> H >> M;

    cout << setprecision(20) << solve() << endl;

    return 0;
}
