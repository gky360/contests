/*
[bitflyer2018-qual] E - 祝日
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

const int MAX_N = 50;
const int MAX_W = 100000;

ll Y, W;
int N, M;
ll D;
ll a[MAX_N];
vector<ll> cb[MAX_W];
map<ll, int> m;
ll anss[MAX_W];

ll calc_btw(ll x, ll y) { return ((y - x - 1 <= D) ? max(0LL, y - x - 1) : 0); }

ll update(ll h, bool is_remove) {
    ll d = is_remove ? -1 : 1;
    ll mh = (m[h] += d);

    if ((is_remove && mh > 0) || (!is_remove && mh > 1)) {
        return 0;
    }

    ll diff = 0;
    ll h_pre = -1, h_next = -1;
    auto iter = m.find(h);
    if (iter != m.begin()) {
        iter--;
        h_pre = iter->first;
        diff += d * calc_btw(h_pre, h);
        iter++;
    }
    if (++iter != m.end()) {
        h_next = iter->first;
        diff += d * calc_btw(h, h_next);
    }
    if (is_remove) {
        m.erase(h);
    }
    diff += d;
    if (h_pre >= 0 && h_next >= 0) {
        diff -= d * calc_btw(h_pre, h_next);
    }
    return diff;
}

void solve() {
    if (N + M == 0) {
        return;
    }

    for (int i = 0; i < N; i++) {
        m[a[i]]++;
    }
    for (int c = 0; c < W; c++) {
        for (ll b : cb[c]) {
            m[b * W + c]++;
        }
    }

    anss[0] = 0;
    ll pre_h = m.begin()->first - 1;
    for (auto &p : m) {
        ll h = p.first;
        anss[0] += calc_btw(pre_h, h) + 1;
        pre_h = h;
    }

    for (int w = 1; w < W; w++) {
        anss[w] = anss[w - 1];

        for (int i = 0; i < N; i++) {
            ll h = a[i] + w - 1;
            anss[w] += update(h, true);
            anss[w] += update(h + 1, false);
        }
        for (ll b : cb[w - 1]) {
            ll h = b * W + w - 1;
            anss[w] += update(h, true);
            anss[w] += update(h + W, false);
        }
    }
}

int main() {
    cin >> Y >> W;
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < M; i++) {
        ll b, c;
        cin >> b >> c;
        cb[c - 1].push_back(b - 1);
    }

    solve();

    for (int i = 0; i < W; i++) {
        cout << anss[i] << endl;
    }

    return 0;
}
