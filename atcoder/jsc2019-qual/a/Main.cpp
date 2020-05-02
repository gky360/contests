/*
[jsc2019-qual] A - Takahashi Calendar
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int M, D;

ll solve() {
    int ans = 0;
    for (int m = 1; m <= M; m++) {
        for (int d = 1; d <= D; d++) {
            int d1 = d % 10;
            int d10 = d / 10;
            if (d1 >= 2 && d10 >= 2 && m == d1 * d10) {
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    cin >> M >> D;

    cout << solve() << endl;

    return 0;
}
