/*
[abc165] E - Rotation Matching
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N, M;

void solve() {
    for (int i = 0; i < M; i++) {
        int a = i + 1, b = N - i;
        if (N % 2 == 0 && i >= (M + 1) / 2) {
            a++;
        }
        cout << a << " " << b << endl;
    }
}

int main() {
    cin >> N >> M;

    solve();

    return 0;
}
