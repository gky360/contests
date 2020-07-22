/*
[past201912-open] B - 増減管理 / Up and Down
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100000;

int N;
int A[MAX_N];

void solve() {
    for (int i = 0; i < N - 1; i++) {
        int d = A[i + 1] - A[i];
        if (d == 0) {
            cout << "stay" << endl;
        } else if (d < 0) {
            cout << "down " << -d << endl;
        } else {
            cout << "up " << d << endl;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    solve();

    return 0;
}
