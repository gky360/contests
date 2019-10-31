/*
[diverta2019] A - Consecutive Integers
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N, K;

ll solve() { return N - K + 1; }

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
