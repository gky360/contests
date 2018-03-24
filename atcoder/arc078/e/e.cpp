// AtCoder Regular Contest 078
// E - Awkward Response

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


bool query(ll n) {
    char c;
    cout << "? " << n << endl;
    cin >> c;
    return c == 'Y';
}

int main() {

    int d;
    ll n, l, r, m;

    for (d = 1, n = 1; d < 11 && query(n); d++, n *= 10) {}
    if (d == 11) {
        for (d = 1, n = 1; d < 11 && !query(n * 10 - 1); d++, n *= 10) {}
        cout << "! " << n << endl;
        return 0;
    }

    l = n / 10;
    r = n;
    m = (l + r + 1) / 2;
    while (r - l > 1) {
        if (query(m * 10)) {
            r = m;
        } else {
            l = m;
        }
        m = (l + r + 1) / 2;
    }

    cout << "! " << m << endl;

    return 0;

}



