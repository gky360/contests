// ARC082
// E - ConvexScore

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 200;
const int MOD = 998244353;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

int N;
int x[MAX_N], y[MAX_N];
int p2[MAX_N + 1], lc[MAX_N + 1];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    p2[0] = 1;
    for (int i = 1; i <= N; i++) {
        p2[i] = (2 * p2[i - 1]) % MOD;
    }

    memset(lc, 0, sizeof(lc));
    for (int i = 0; i < N; i++) {
        map<pii, int> slope;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            if (dx < 0) {
                dx *= -1;
                dy *= -1;
            }
            if (dx == 0) {
                dy = 1;
            } else if (dy == 0) {
                dx = 1;
            } else {
                int d = gcd(dx, abs(dy));
                dx /= d;
                dy /= d;
            }
            slope[pii(dx, dy)]++;
        }
        for (auto &p : slope) {
            lc[p.second + 1]++;
        }
    }

    int ans = (p2[N] + MOD - (1 + N + N * (N - 1) / 2)) % MOD;
    for (int i = 3; i <= N; i++) {
        int sel =
            1LL * (MOD - p2[i] + (1 + i + i * (i - 1) / 2)) * (lc[i] / i) % MOD;
        (ans += sel) %= MOD;
    }

    cout << ans << endl;

    return 0;
}
