/*
[agc038] A - 01 Matrix
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int H, W, A, B;

void solve() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << (((i < B) != (j < A)) ? 1 : 0);
        }
        cout << endl;
    }
}

int main() {
    cin >> H >> W >> A >> B;

    solve();

    return 0;
}
