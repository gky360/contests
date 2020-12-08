/*
[abc163] C - management
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;

int N;
int A[MAX_N];
int ans[MAX_N];

void solve() {
    for (int i = 1; i < N; i++) ans[A[i]]++;
    REP(i, N) cout << ans[i] << endl;
}

int main() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    solve();

    return 0;
}
