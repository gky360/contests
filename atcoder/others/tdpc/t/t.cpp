// TDPC
// T - フィボナッチ

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_K = 1000;
constexpr int MOD = 1e9 + 7;

int K, N;

vector<int> mul(const vector<int> &a, const vector<int> &b) {
    vector<int> c(2 * K, 0);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            (c[i + j] += 1LL * a[i] * b[j] % MOD) %= MOD;
        }
    }
    for (int i = 2 * K - 2; i >= K; i--) {
        for (int j = i - K; j < i; j++) {
            (c[j] += c[i]) %= MOD;
        }
    }
    c.resize(K);
    return c;
}

int main() {
    cin >> K >> N;

    vector<int> a(K, 0), b(K, 0);
    a[1] = b[0] = 1;

    for (int i = N - 1; i > 0; i >>= 1, a = mul(a, a)) {
        if (i & 1) {
            b = mul(a, b);
        }
    }

    int ans = 0;
    for (int i = 0; i < K; i++) {
        (ans += b[i]) %= MOD;
    }

    cout << ans << endl;

    return 0;
}
