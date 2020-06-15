/*
[abc144] E - Gluttony
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;
const ll INF = 1e17;

int N;
int A[MAX_N];
int F[MAX_N];
ll K;

bool can(ll t) {
    ll k = 0;
    for (int i = 0; i < N; i++) {
        k += max(0LL, A[i] - t / F[i]);
    }
    return k <= K;
}

ll solve() {
    sort(A, A + N);
    sort(F, F + N, greater<int>());

    ll ng = -1, ok = INF;
    while (ok - ng > 1) {
        ll t = (ok + ng) / 2;
        if (can(t)) {
            ok = t;
        } else {
            ng = t;
        }
    }
    return ok;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> F[i];
    }

    cout << solve() << endl;

    return 0;
}
