/*
[aising2020] D - Anything Goes to Zero
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
string X;
int f[MAX_N];
int pa[MAX_N + 1], pb[MAX_N + 1];

int dfs(int n) {
    if (n == 0) return 0;
    int pc = 0;
    for (int m = n; m > 0; m >>= 1) {
        if (m & 1) pc++;
    }
    return dfs(n % pc) + 1;
}

void solve() {
    reverse(ALL(X));
    REP(i, N) f[i] = dfs(i);

    int c = 0;
    REP(i, N) {
        if (X[i] == '1') c++;
    }

    pa[0] = pb[0] = 1;
    REP(i, N) {
        if (c - 1 > 0) pa[i + 1] = (pa[i] * 2) % (c - 1);
        pb[i + 1] = (pb[i] * 2) % (c + 1);
    }

    int xa = 0, xb = 0;
    REP(i, N) {
        if (X[i] == '1') {
            if (c - 1 > 0) (xa += pa[i]) %= (c - 1);
            (xb += pb[i]) %= (c + 1);
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        int ans;
        if (c == 0)
            ans = 1;
        else if (c == 1 && X[i] == '1')
            ans = 0;
        else {
            int x = X[i] == '1' ? (xa - pa[i] + (c - 1)) % (c - 1)
                                : (xb + pb[i]) % (c + 1);
            ans = f[x] + 1;
        }
        cout << ans << endl;
    }
}

int main() {
    cin >> N;
    cin >> X;

    solve();

    return 0;
}
