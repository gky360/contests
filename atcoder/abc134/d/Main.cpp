/*
[abc134] D - Preparing Boxes
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 2e5;

int N;
int a[MAX_N + 1];
int ans[MAX_N + 1];

void solve() {
    int M = 0;
    for (int j = N; j > 0; j--) {
        ll s = 0;
        for (int i = j; i <= N; i += j) {
            s += ans[i];
        }
        if (s % 2 != a[j]) {
            ans[j] = 1;
            M++;
        }
    }

    cout << M << endl;
    for (int i = 1; i <= N; i++) {
        if (ans[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    solve();

    return 0;
}
