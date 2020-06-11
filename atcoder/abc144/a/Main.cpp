/*
[abc144] A - 9x9
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
    if (A > 9 || B > 9) {
        return -1;
    }
    return A * B;
}

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
