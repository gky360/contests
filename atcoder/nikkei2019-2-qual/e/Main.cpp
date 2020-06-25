/*
[nikkei2019-2-qual] E - Non-triangular Triplets
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N, K;

void solve() {
    int L = (N + 1) / 2;
    if (K > L) {
        cout << -1 << endl;
        return;
    }

    int m = N % 2;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        if (i < L) {
            a = K + 2 * i, b = K + 3 * L - 1 - m - i, c = K + 4 * L - 2 * m + i;
        } else {
            int j = i - L;
            a = K + 1 + 2 * j, b = K + 4 * L - 1 - 2 * m - j,
            c = K + 4 * L - 2 * m + i;
        }
        cout << a << " " << b << " " << c << endl;
    }
}

int main() {
    cin >> N >> K;

    solve();

    return 0;
}
