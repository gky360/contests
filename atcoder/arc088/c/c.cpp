// AtCoder Regular Contest 088
// C - Multiple Gift

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

ll X, Y;

int main() {
    ll a;
    int ans;

    cin >> X >> Y;
    a = X;
    for (ans = 1; a * 2 <= Y; ans++) {
        a *= 2;
    }

    cout << ans << endl;

    return 0;
}
