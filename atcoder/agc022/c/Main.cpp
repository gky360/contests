// AGC022
// C - Remainder Game

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 50;

int N;
int a[MAX_N], b[MAX_N];

bool can(ll pat) {
    bool g[MAX_N + 1][MAX_N + 1];
    memset(g, 0, sizeof(g));

    for (int i = 0; i < MAX_N; i++) {
        g[i][i] = true;
    }
    for (int i = 1; i <= MAX_N; i++) {
        if ((pat >> (i - 1)) & 1) {
            for (int j = 0; j <= MAX_N; j++) {
                g[j][j % i] = true;
            }
        }
    }

    for (int k = 0; k <= MAX_N; k++) {
        for (int i = 0; i <= MAX_N; i++) {
            for (int j = 0; j <= MAX_N; j++) {
                g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (!g[a[i]][b[i]]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    ll ans = 0;
    for (int i = MAX_N; i >= 0; i--) {
        ll b = ((1LL << i) - 1) | ans;
        if (!can(b)) {
            if (i == MAX_N) {
                cout << -1 << endl;
                return 0;
            }
            ans |= (1LL << i);
        }
    }

    ans <<= 1;
    cout << ans << endl;

    return 0;
}
