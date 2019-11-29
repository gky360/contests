/*
[agc034] C - Tests
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
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
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
ll X;
ll b[MAX_N], l[MAX_N], u[MAX_N];
int idx[MAX_N];
ll s[MAX_N + 2];
ll lb;

ll calc(int i) { return (X - b[i]) * u[i] + b[i] * l[i]; }

bool cmp(int x, int y) { return calc(x) > calc(y); }

bool can(ll t) {
    ll q = t / X;
    for (int i = 0; i < N; i++) {
        ll d = lb;
        if (i < q) {
            d += s[q + 1] - calc(idx[i]);
        } else {
            d += s[q];
        }
        d += l[idx[i]] * min(b[idx[i]], t % X) +
             u[idx[i]] * max(0LL, t % X - b[idx[i]]);

        if (d >= 0) {
            return true;
        }
    }

    return false;
}

ll solve() {
    for (int i = 0; i < N; i++) {
        idx[i] = i;
    }
    sort(idx, idx + N, cmp);

    lb = 0;
    s[0] = 0;
    for (int i = 0; i < N; i++) {
        s[i + 1] = s[i] + calc(idx[i]);
        lb += -l[i] * b[i];
    }
    s[N + 1] = s[N];

    ll ok = 1LL * X * N;
    ll ng = -1;
    while (ok - ng > 1) {
        ll m = (ok + ng) / 2;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }

    return ok;
}

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> b[i] >> l[i] >> u[i];
    }

    cout << solve() << endl;

    return 0;
}
