/*
[abc158] B - Count Balls
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

ll N, A, B;

ll solve() {
    ll d = N / (A + B);
    ll ans = d * A + min(A, N - d * (A + B));
    return ans;
}

int main() {
    cin >> N >> A >> B;

    cout << solve() << endl;

    return 0;
}
