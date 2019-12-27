/*
[abc130] C - Rectangle Cutting
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

double W, H, x, y;

void solve() {
    cout << setprecision(15) << W * H * 0.5 << " "
         << (x == W * 0.5 && y == H * 0.5) << endl;
}

int main() {
    cin >> W >> H >> x >> y;

    solve();

    return 0;
}
