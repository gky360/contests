/*
[abc133] D - Rain Flows into Dams
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
int ans[MAX_N];

void solve() {
    int s = 0;
    for (int i = 0; i < N; i++) {
        s += ((i & 1) ? -1 : 1) * A[i];
    }
    ans[0] = s;
    for (int i = 1; i < N; i++) {
        ans[i] = 2 * (A[i - 1] - ans[i - 1] / 2);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    solve();
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
