/*
[abc135] C - City Savers
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
int A[MAX_N + 1], B[MAX_N];

ll solve() {
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int d = min(A[i], B[i]);
        ans += d;
        int e = min(A[i + 1], B[i] - d);
        A[i + 1] -= e;
        ans += e;
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N + 1; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    cout << solve() << endl;

    return 0;
}
