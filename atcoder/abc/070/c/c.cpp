// AtCoder Beginner Contest 070
// C - Multiple Clocks

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


int N;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {

    ll t;
    ll ans;

    cin >> N;
    ans = 1;
    for (int i = 0; i < N; i++) {
        cin >> t;
        ans = t / gcd(t, ans) * ans;
    }

    cout << ans << endl;

    return 0;

}



