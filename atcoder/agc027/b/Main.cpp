/*
[agc027] B - Garbage Collector
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

const int MAX_N = 200000;
const ll INF = 1e17;

ll N;
ll X;
ll x[MAX_N];
ll s[MAX_N + 1];

ll solve() {
    s[0] = 0;
    for (int i = 1; i <= N; i++) {
        s[i] = s[i - 1] + x[N - i];
    }

    ll ans = INF;
    for (ll m = 1; m <= N; m++) {
        ll sum_e = X * (N + m);
        for (ll d = 0; d <= N / m; d++) {
            ll e = (d == 0) ? 5 : (2 * d + 3);
            sum_e += e * (s[min(N, (d + 1) * m)] - s[d * m]);
            if (sum_e >= ans) {
                break;
            }
        }
        ans = min(ans, sum_e);
    }

    return ans;
}

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    cout << solve() << endl;

    return 0;
}
