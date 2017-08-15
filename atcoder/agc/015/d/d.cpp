// AtCoder Grand Contest 015
// D - A or...or B Problem

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


ll A, B;

int main() {

    ll d, k, ans;

    cin >> A >> B;
    for (d = (1LL << 60); d > 0; d >>= 1) {
        if ((A & d) != (B & d)) {
            break;
        }
    }
    for (k = (d >> 1); k > 0; k >>= 1) {
        if (B & k) {
            break;
        }
    }
    k = max(k - 1, 0LL);
    d = max(d - 1, 0LL);
    ans = (B | k) - A + 1;
    ans += (B | d) - max((B | k) + 1, (B & ~d) | (A & d)) + 1;

    cout << ans << endl;

    return 0;

}



