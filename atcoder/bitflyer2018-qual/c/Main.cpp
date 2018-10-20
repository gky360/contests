/*
[bitflyer2018-qual] C - 徒歩圏内
*/

#include <algorithm>
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

int N, D;
int x[MAX_N];

ll comb2(ll n) {
    if (n < 2) {
        return 0;
    }
    return n * (n - 1) / 2;
}

ll solve() {
    int l[MAX_N], r[MAX_N];
    for (int i = 0; i < N; i++) {
        r[i] = (upper_bound(x, x + N, x[i] + D) - x) - 1 - i;
        l[i] = i - (lower_bound(x, x + N, x[i] - D) - x);
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += 1LL * l[i] * r[i];
        ans -= comb2(l[i]);
    }

    return ans;
}

int main() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    cout << solve() << endl;

    return 0;
}
