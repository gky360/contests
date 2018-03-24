// ARC083
// D - Restoring Road Network

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 300;

int N;
int g[MAX_N][MAX_N];

ll solve() {
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool is_adj = true;
            for (int k = 0; k < N; k++) {
                if (k == i || k == j) {
                    continue;
                }
                if (g[i][j] > g[i][k] + g[k][j]) {
                    return -1;
                }
                if (g[i][j] == g[i][k] + g[k][j]) {
                    is_adj = false;
                }
            }
            if (is_adj) {
                ans += g[i][j];
            }
        }
    }
    return ans / 2;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}
