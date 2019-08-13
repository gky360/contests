/*
[nikkei2019-final] B - Big Integers
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N, M, K;
int A[MAX_N], B[MAX_N];

int solve() {
    if (N != M) {
        return N - M;
    }
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            return A[i] - B[i];
        }
    }

    return 0;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    int ans = solve();
    cout << (ans == 0 ? "Same" : (ans > 0 ? "Y" : "X")) << endl;

    return 0;
}
