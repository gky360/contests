/*
[abc158] C - Tax Increase
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int A, B;

ll solve() {
    for (int i = 0; i <= 20000; i++) {
        if (i * 8 / 100 == A && i * 10 / 100 == B) {
            return i;
        }
    }

    return -1;
}

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
