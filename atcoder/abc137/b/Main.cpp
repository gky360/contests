/*
[abc137] B - One Clue
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int K, X;

void solve() {
    for (int i = X - K + 1; i < X + K; i++) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    cin >> K >> X;

    solve();

    return 0;
}
