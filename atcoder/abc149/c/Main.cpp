/*
[abc149] C - Next Prime
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_X = 1e5 + 10;

int X;
bool p[MAX_X];

ll solve() {
    memset(p, true, sizeof(p));
    for (int d = 2; d < MAX_X; d++) {
        if (!p[d]) continue;
        for (int i = 2 * d; i < MAX_X; i += d) {
            p[i] = false;
        }
    }

    for (int i = X; i < MAX_X; i++) {
        if (p[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    cin >> X;

    cout << solve() << endl;

    return 0;
}
