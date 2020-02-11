/*
[abc133] A - T or T
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N, A, B;

ll solve() { return min(N * A, B); }

int main() {
    cin >> N >> A >> B;

    cout << solve() << endl;

    return 0;
}
