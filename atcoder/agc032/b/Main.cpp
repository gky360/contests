/*
[agc032] B - Balanced Neighbors
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N;

void solve() {
    cout << (N / 2) * (N / 2 - 1) / 2 * 4 + (N % 2 == 0 ? 0 : N - 1) << endl;
    int s = N / 2 * 2 + 1;
    for (int i = 1; i <= N / 2; i++) {
        for (int j = i + 1; j <= N / 2; j++) {
            cout << i << " " << j << endl;
            cout << s - i << " " << j << endl;
            cout << i << " " << s - j << endl;
            cout << s - i << " " << s - j << endl;
        }
    }

    if (N % 2 == 1) {
        for (int i = 1; i < N; i++) {
            cout << i << " " << N << endl;
        }
    }
}

int main() {
    cin >> N;

    solve();

    return 0;
}
