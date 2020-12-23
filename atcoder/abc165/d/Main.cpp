/*
[abc165] D - Floor Function
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

ll A, B, N;

ll solve() {
    ll ans = A * min(B - 1, N) / B;
    return ans;
}

int main() {
    cin >> A >> B >> N;

    cout << solve() << endl;

    return 0;
}
