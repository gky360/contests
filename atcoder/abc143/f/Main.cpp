/*
[abc143] F - Distinct Numbers
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 3e5;

int N;
int A[MAX_N];
int c[MAX_N + 1], d[MAX_N + 1];

void solve() {
    for (int i = 0; i < N; i++) {
        c[A[i]]++;
    }
    for (int i = 1; i <= N; i++) {
        d[c[i]]++;
    }

    int skd[MAX_N + 1], sd[MAX_N + 1];
    skd[0] = 0, sd[0] = d[0];
    for (int i = 1; i <= N; i++) {
        skd[i] = skd[i - 1] + i * d[i];
        sd[i] = sd[i - 1] + d[i];
    }

    int f[MAX_N + 1];
    for (int i = 1; i <= N; i++) {
        f[i] = (skd[i] + i * (sd[N] - sd[i])) / i;
    }

    int ans = N;
    for (int k = 1; k <= N; k++) {
        while (ans > 0 && f[ans] < k) {
            ans--;
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
