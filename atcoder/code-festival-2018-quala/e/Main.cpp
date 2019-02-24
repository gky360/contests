/*
[code-festival-2018-quala] E - オレンジとみかん
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

const int MAX_N = 100000 + 100000;
const ll INF = 1e18;

int X, Y, N;
ll A[MAX_N], B[MAX_N];
int S;
vector<pair<ll, pii>> cands;
int bad;
int lxs[MAX_N], rxs[MAX_N];
int lx_sum, rx_sum;

void calc_right(int n, int x) {
    if (rxs[n] == -1) {
        lxs[n] = rxs[n] = x;
        bad--;
        lx_sum += x;
        rx_sum += x;
    } else {
        if (lxs[n] == x + 1) {
            lxs[n]--;
            lx_sum--;
        } else {
            assert(rxs[n] == x - 1);
            rxs[n]++;
            rx_sum++;
        }
    }
}

void calc_left(int n, int x) {
    if (lxs[n] == x && rxs[n] == x) {
        lxs[n] = rxs[n] = -1;
        bad++;
        lx_sum -= x;
        rx_sum -= x;
    } else {
        if (lxs[n] == x) {
            lxs[n]++;
            lx_sum++;
        } else {
            assert(rxs[n] == x);
            rxs[n]--;
            rx_sum--;
        }
    }
}

bool can(ll k) {
    fill(lxs, lxs + N, -1);
    fill(rxs, rxs + N, -1);
    bad = N;
    lx_sum = rx_sum = 0;

    int r = 0;
    for (int l = 0; l < (int)cands.size(); l++) {
        ll lm = cands[l].first;
        for (; r < (int)cands.size() && cands[r].first - k <= lm; r++) {
            int rn = cands[r].second.first, rx = cands[r].second.second;
            calc_right(rn, rx);
        }
        if (bad == 0 && lx_sum <= X && X <= rx_sum) {
            return true;
        }
        int ln = cands[l].second.first, lx = cands[l].second.second;
        calc_left(ln, lx);
    }

    return false;
}

ll solve() {
    S = (X + Y) / N;

    for (int n = 0; n < N; n++) {
        for (int x = 0; x <= S; x++) {
            ll m = A[n] * x + B[n] * (S - x);
            cands.push_back(make_pair(m, pii(n, x)));
        }
    }
    sort(cands.begin(), cands.end());

    ll ng = -1, ok = INF;
    while (ok - ng > 1) {
        ll k = (ok + ng) / 2;
        if (can(k)) {
            ok = k;
        } else {
            ng = k;
        }
    }

    return ok;
}

int main() {
    cin >> X >> Y >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    cout << solve() << endl;

    return 0;
}
