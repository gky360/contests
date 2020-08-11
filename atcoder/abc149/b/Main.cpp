/*
[abc149] B - Greedy Takahashi
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

ll A, B, K;

void solve() {
    ll r = min(A, K);
    A -= r, K -= r;
    r = min(B, K);
    B -= r, K -= r;

    cout << A << " " << B << endl;
}

int main() {
    cin >> A >> B >> K;

    solve();

    return 0;
}
