/*
[abc149] E - Handshake
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MAX_A = 2 * 1e5;

int N;
ll M;
int A[MAX_N];
int c[MAX_A + 1];
ll s[MAX_A + 1];

bool can(int t) {
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += N - c[max(0, t - A[i] - 1)];
    }
    return cnt >= M;
}

ll calc(int t) {
    ll cnt = 0, ret = 0;
    for (int i = 0; i < N; i++) {
        int k = N - c[max(0, t - A[i])];
        cnt += k;
        ret += s[MAX_A] - s[max(0, t - A[i])] + 1LL * k * A[i];
    }
    ret += (M - cnt) * t;
    return ret;
}

ll solve() {
    for (int i = 0; i < N; i++) {
        c[A[i]]++;
        s[A[i]] += A[i];
    }
    for (int i = 1; i <= MAX_A; i++) {
        c[i] += c[i - 1];
        s[i] += s[i - 1];
    }

    int ok = 0, ng = MAX_A + 1;
    while (ng - ok > 1) {
        int m = (ng + ok) / 2;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }

    return calc(ok);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
