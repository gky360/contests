/*
[nikkei2019-final] A - Abundant Resources
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 3000;

int N;
int A[MAX_N];

void solve() {
    for (int k = 1; k <= N; k++) {
        ll s = 0;
        for (int i = 0; i < k; i++) {
            s += A[i];
        }
        ll ans = s;
        for (int i = 0; i + k < N; i++) {
            s -= A[i];
            s += A[i + k];
            ans = max(ans, s);
        }
        cout << ans << endl;
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
