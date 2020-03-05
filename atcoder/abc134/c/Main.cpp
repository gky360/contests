/*
[abc134] C - Exception Handling
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 200000;

int N;
int A[MAX_N];
int ml[MAX_N + 1], mr[MAX_N + 1];

void solve() {
    for (int i = 0; i < N; i++) {
        ml[i + 1] = max(ml[i], A[i]);
    }
    for (int i = N; i > 0; i--) {
        mr[i - 1] = max(mr[i], A[i - 1]);
    }

    for (int i = 0; i < N; i++) {
        cout << max(ml[i], mr[i + 1]) << endl;
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
