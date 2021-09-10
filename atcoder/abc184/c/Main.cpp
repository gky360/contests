/*
[abc184] C - Super Ryuma
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

ll r1, c1, r2, c2;

bool can(int x, int y, int s, int t) {
    return x + y == s + t || x - y == s - t || abs(x - s) + abs(y - t) <= 3;
}

ll solve() {
    if (r1 == r2 && c1 == c2) return 0;
    if (can(r2, c2, r1, c1)) return 1;
    for (int i = -3; i <= 3; i++) {
        for (int j = -3; j <= 3; j++) {
            if (abs(i) + abs(j) <= 3 && can(r2, c2, r1 + i, c1 + j)) return 2;
        }
    }
    if ((r1 + c1 + r2 + c2) % 2 == 0) return 2;
    return 3;
}

int main() {
    cin >> r1 >> c1;
    cin >> r2 >> c2;

    cout << solve() << endl;

    return 0;
}
