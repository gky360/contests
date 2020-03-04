/*
[abc134] B - Golden Apple
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N, D;

ll solve() { return (N + 2 * D) / (2 * D + 1); }

int main() {
    cin >> N >> D;

    cout << solve() << endl;

    return 0;
}
