/*
[abc155] D - Pairs
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;
const int INF = 1e9 + 1;

int N;
ll K;
int A[MAX_N];

bool can(int a, int s, int t) {
    ll cnt = 0;
    for (int i = s; i < t; i++) {
        if (A[i] == 0) {
            if (0 <= a) cnt += i;
        } else if (A[i] > 0) {
            cnt += upper_bound(A + s, A + i, (a + A[i] - 1) / A[i]) - A;
        } else {
            cnt += i - (lower_bound(A + s, A + i, a / A[i]) - A);
        }
    }

    return cnt >= K;
}

ll calc(int s, int t) {
    int ng = -INF, ok = INF;
    while (ok - ng > 1) {
        int m = (ok + ng) / 2;
        if (can(m, s, t)) {
            ok = m;
        } else {
            ng = m;
        }
    }
    return ok;
}

ll solve() {
    sort(A, A + N);

    ll a = lower_bound(A, A + N, 0) - A;
    ll b = (upper_bound(A, A + N, 0) - A) - a;
    ll c = N - a - b;
    ll p = a * c, q = b * (a + c) + b * (b - 1) / 2,
       r = a * (a - 1) / 2 + c * (c - 1) / 2;

    if (K <= p) {
        return calc(0, p);
    }
    if (K <= p + q) {
        return 0;
    }
    return calc(p + q, N);
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
