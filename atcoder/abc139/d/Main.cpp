/*
[abc139] D - ModSum
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;

ll solve() {
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        ans += i;
    }

    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
