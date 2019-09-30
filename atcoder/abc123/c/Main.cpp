/*
[abc123] C - Five Transportations
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const ll INF = 1e18;

ll N;
ll A[5];

ll solve() {
    ll d = *min_element(A, A + 5);
    return ((N + d - 1) / d + 5 - 1);
}

int main() {
    cin >> N;
    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
