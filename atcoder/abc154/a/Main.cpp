/*
[abc154] A - Remaining Balls
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string S, T;
int A, B;
string U;

void solve() {
    if (U == S) {
        A--;
    } else {
        B--;
    }

    cout << A << " " << B << endl;
}

int main() {
    cin >> S >> T;
    cin >> A >> B;
    cin >> U;

    solve();

    return 0;
}
