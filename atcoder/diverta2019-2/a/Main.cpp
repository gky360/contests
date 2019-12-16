/*
[diverta2019-2] A - Ball Distribution
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N, K;

ll solve() { return K == 1 ? 0 : N - K; }

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
