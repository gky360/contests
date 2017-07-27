// AtCoder Grand Contest 017
// A - Biscuits

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


int N, P;

int main() {

    bool is_all_even = true;
    int a;
    ll ans;

    cin >> N >> P;
    for (int i = 0; i < N; i++) {
        cin >> a;
        is_all_even = is_all_even && (a % 2 == 0);
    }

    if (is_all_even) {
        ans = (P % 2 == 0 ? (1LL << N) : 0LL);
    } else {
        ans = 1LL << (N - 1);
    }

    cout << ans << endl;

    return 0;

}



