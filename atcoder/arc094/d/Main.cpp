// ARC094
// D - Worst Case

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int Q;

ll solve(ll a, ll b) {
    if (a > b) {
        swap(a, b);
    }

    if (b - a <= 1) {
        return 2 * a - 2;
    }
    ll c = sqrt(a * b);
    if (c * c == a * b) {
        c--;
    }
    if (c * (c + 1) >= a * b) {
        return 2 * c - 2;
    }
    return 2 * c - 1;
}

int main() {
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll a, b;
        cin >> a >> b;

        cout << solve(a, b) << endl;
    }

    return 0;
}
