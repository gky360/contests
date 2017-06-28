// AtCoder Grand Contest 015
// A - A+...+B Problem

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


ll N, A, B;

int main() {

    ll ans;

    cin >> N >> A >> B;

    if (A > B) {
        ans = 0;
    } else {
        ans = max(0LL, (B - A) * (N - 2) + 1);
    }
    cout << ans << endl;

    return 0;

}



