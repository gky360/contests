/*
[abc135] A - Harmony
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int A, B;

void solve() {
    if (A < B) {
        swap(A, B);
    }
    if ((B - A) % 2 != 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << (A + B) / 2 << endl;
}

int main() {
    cin >> A >> B;

    solve();

    return 0;
}
