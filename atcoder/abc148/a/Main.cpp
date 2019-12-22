/*
[abc148] A - Round One
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int A, B;

ll solve() {
    if (A > B) {
        swap(A, B);
    }
    if (A == 2 && B == 3) {
        return 1;
    }
    if (A == 1 && B == 3) {
        return 2;
    }

    return 3;
}

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
