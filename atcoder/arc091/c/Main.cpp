// ARC091
// C - Flip,Flip, and Flip......

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

ll N, M;

ll solve(ll n, ll m) {
    if (n == 1 && m == 1) {
        return 1;
    }
    if (n > 1 && m == 1) {
        return n - 2;
    }
    if (n == 1 && m > 1) {
        return m - 2;
    }
    return max(0LL, n - 2) * max(0LL, m - 2);
}

int main() {
    cin >> N >> M;

    cout << solve(N, M) << endl;

    return 0;
}
