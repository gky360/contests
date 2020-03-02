/*
[agc035] C - Skolem XOR Tree
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N;

void solve() {
    int k = 1;
    while ((k << 1) <= N) {
        k <<= 1;
    }
    if (k == N) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;

    cout << N + 1 << " " << 3 << endl;
    for (int i = 1; i < (N + 1) / 2; i++) {
        cout << 1 << " " << 2 * i << endl;
        cout << 2 * i << " " << 2 * i + 1 << endl;
        cout << 1 << " " << N + 2 * i + 1 << endl;
        cout << N + 2 * i + 1 << " " << N + 2 * i << endl;
    }
    if (N % 2 == 0) {
        cout << k << " " << N << endl;
        cout << N + (N ^ k ^ 1) << " " << N + N << endl;
    }
}

int main() {
    cin >> N;

    solve();

    return 0;
}
