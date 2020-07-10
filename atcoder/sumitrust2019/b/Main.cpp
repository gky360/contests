/*
[sumitrust2019] B - Tax Rate
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;

void solve() {
    int ans = (N * 100 + 107) / 108;
    if (ans * 108 / 100 != N) {
        cout << ":(" << endl;
        return;
    }

    cout << ans << endl;
}

int main() {
    cin >> N;

    solve();

    return 0;
}
