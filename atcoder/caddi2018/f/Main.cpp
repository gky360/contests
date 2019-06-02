/*
[caddi2018] F - Square
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 1e5;
const int MAX_M = 5e4;
const ll MOD = 998244353;

int N, M;
int a[MAX_M], b[MAX_M], c[MAX_M];
map<pii, int> m;
ll dp[MAX_N][2];

bool check(int h, int w, int c) {
    auto kv = m.find(pii(h, w));
    return kv == m.end() || kv->second == c;
}

ll solve() {
    for (int i = 0; i < M; i++) {
        m[pii(a[i], b[i])] = c[i];
    }

    ll cnt = 1LL * (N - 3) * (N - 2);
    for (auto &kv0 : m) {
        int h = kv0.first.first;
        int w = kv0.first.second;
        if (abs(h - w) < 3) {
            continue;
        }
        auto kv1 = m.find(pii(w, h));
        if (kv1 != m.end() && kv0.second != kv1->second) {
            return 0;
        }
        if (kv1 != m.end()) {
            cnt--;
        } else {
            cnt -= 2;
        }
    }

    ll ans = 1;
    ll po = 2;
    for (ll i = cnt / 2; i > 0; i >>= 1) {
        if (i & 1) {
            (ans *= po) %= MOD;
        }
        (po *= po) %= MOD;
    }

    for (int b = 0; b < (1 << 3); b++) {
        int p = (b >> 0) & 1;
        int q = (b >> 1) & 1;
        int r = (b >> 2) & 1;
        int k = (p + q + r) % 2;
        if (check(0, 0, p) && check(0, 1, q) && check(1, 0, r) &&
            check(1, 1, k)) {
            dp[1][k] += 1;
        }
    }

    for (int n = 2; n < N; n++) {
        for (int k = 0; k < 2; k++) {
            for (int b = 0; b < (1 << 3); b++) {
                int p = (b >> 0) & 1;
                int q = (b >> 1) & 1;
                int r = (b >> 2) & 1;
                int s = (q + r + k) % 2;
                int t = (p + k) % 2;
                if (check(n - 2, n, p) && check(n - 1, n, q) &&
                    check(n, n, r) && check(n, n - 1, s) &&
                    check(n, n - 2, t)) {
                    (dp[n][r] += dp[n - 1][k]) %= MOD;
                }
            }
        }
    }

    ll ans_d = (dp[N - 1][0] + dp[N - 1][1]) % MOD;
    (ans *= ans_d) %= MOD;

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }

    cout << solve() << endl;

    return 0;
}
