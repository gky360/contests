/*
[yahoo-procon2019-final] A - Affiches
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

double HW[2], AB[2];

double solve() {
    double ans = 1;
    for (int i = 0; i < 2; i++) {
        double l = min(AB[i], HW[i] - AB[i]);
        ans *= (2 * l * l * l - 3 * HW[i] * l * l + 6 * HW[i] * AB[i] * l -
                6 * AB[i] * AB[i] * l) /
               (3 * (HW[i] - AB[i]) * (HW[i] - AB[i]));
    }
    return ans;
}

int main() {
    cin >> HW[0] >> HW[1] >> AB[0] >> AB[1];

    cout << setprecision(15) << solve() << endl;

    return 0;
}
