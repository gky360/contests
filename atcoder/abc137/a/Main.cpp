/*
[abc137] A - +-x
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int A, B;

ll solve() { return max(max(A + B, A - B), A * B); }

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
