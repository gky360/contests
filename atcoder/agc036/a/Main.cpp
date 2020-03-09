/*
[agc036] A - Triangle
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const ll MAX_X = 1e9;

ll S;
ll ans[2][3];

void solve() {
    ans[0][0] = 0;
    ans[1][0] = 0;
    ans[0][1] = MAX_X;
    ans[1][1] = 1;
    ans[0][2] = MAX_X - (S + MAX_X - 1) % MAX_X - 1;
    ans[1][2] = (S + MAX_X - 1) / MAX_X;

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 2; i++) {
            cout << ans[i][j] << " ";
        }
    }
    cout << endl;
}

int main() {
    cin >> S;

    solve();

    return 0;
}
