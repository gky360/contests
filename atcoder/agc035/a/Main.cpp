/*
[agc035] A - XOR Circle
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
int a[MAX_N];

bool solve() {
    if (a[N - 1] != 0 && N % 3 != 0) {
        return false;
    }
    sort(a, a + N);

    return (a[0] == a[N / 3 - 1] && a[N / 3] == a[2 * N / 3 - 1] &&
            a[2 * N / 3] == a[N - 1] && (a[0] ^ a[N / 3] ^ a[2 * N / 3]) == 0);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
