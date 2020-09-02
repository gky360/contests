/*
[keyence2020] A - Painting
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int H, W, N;

ll solve() {
    int d = max(H, W);

    return (N + d - 1) / d;
}

int main() {
    cin >> H >> W >> N;

    cout << solve() << endl;

    return 0;
}
