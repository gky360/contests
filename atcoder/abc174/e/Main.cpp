/*
[abc174] E - Logs
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
const ll MAX_A = 1e9;

int N;
ll K;
ll A[MAX_N];

bool can(ll x) {
    ll ret = 0;
    REP(i, N) ret += (A[i] + x - 1) / x - 1;
    return ret <= K;
}

ll solve() {
    ll ok = MAX_A, ng = 0;
    while (ok - ng > 1) {
        ll m = (ok + ng) / 2;
        if (can(m))
            ok = m;
        else
            ng = m;
    }

    return ok;
}

int main() {
    cin >> N >> K;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
