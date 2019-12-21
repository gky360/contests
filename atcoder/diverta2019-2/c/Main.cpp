/*
[diverta2019-2] C - Successive Subtraction
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
int A[MAX_N];

void solve() {
    int idx[MAX_N];
    for (int i = 0; i < N; i++) {
        idx[i] = i;
    }
    sort(idx, idx + N, [](int a, int b) { return A[a] < A[b]; });
    sort(A, A + N);
    int x = lower_bound(A, A + N, 0) - A;
    x = max(min(x, N - 1), 1);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (i < x) ? -A[i] : A[i];
    }
    cout << ans << endl;

    for (int i = x; i < N - 1; i++) {
        cout << A[0] << " " << A[i] << endl;
        A[0] -= A[i];
    }
    for (int i = 0; i < x; i++) {
        cout << A[N - 1] << " " << A[i] << endl;
        A[N - 1] -= A[i];
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
