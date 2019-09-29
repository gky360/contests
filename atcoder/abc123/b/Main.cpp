/*
[abc123] B - Five Dishes
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int A[5];

ll solve() {
    int s = 0;
    for (int i = 0; i < 5; i++) {
        s += (A[i] + 9) / 10 * 10;
    }
    int d = 0;
    for (int i = 0; i < 5; i++) {
        if (A[i] % 10 > 0) {
            d = max(d, 10 - A[i] % 10);
        }
    }
    return s - d;
}

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
