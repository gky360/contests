/*
[sumitrust2019] C - 100 to 105
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int X;

ll solve() {
    int n = X / 100;

    return X <= n * 105 ? 1 : 0;
}

int main() {
    cin >> X;

    cout << solve() << endl;

    return 0;
}
