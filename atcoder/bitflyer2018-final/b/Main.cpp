/*
[bitflyer2018-final] B - 交通費
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

const int MAX_N = 100000;
const int MAX_Q = 100000;

int N, Q;
ll x[MAX_N];
ll cs[MAX_Q], ds[MAX_Q];
ll s[MAX_N + 1];

ll solve_q(ll c, ll d) {
    int li = lower_bound(x, x + N, c - d) - x;
    int ci = lower_bound(x, x + N, c) - x;
    int ri = upper_bound(x, x + N, c + d) - x;

    ll ans = ((ci - li) * c - (s[ci] - s[li])) +
             ((s[ri] - s[ci]) - (ri - ci) * c) + d * (N - (ri - li));

    return ans;
}

void solve() {
    s[0] = 0;
    for (int i = 0; i < N; i++) {
        s[i + 1] = s[i] + x[i];
    }

    for (int i = 0; i < Q; i++) {
        cout << solve_q(cs[i], ds[i]) << endl;
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < Q; i++) {
        cin >> cs[i] >> ds[i];
    }

    solve();

    return 0;
}
