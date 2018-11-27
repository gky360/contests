/*
[arc099] D - Snuke Numbers
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

const double EPS = 1e-6;

int K;

double f(ll a) {
    int ret = 0;
    for (ll i = a; i > 0; i /= 10) {
        ret += i % 10;
    }
    return (double)a / ret;
}

void solve() {
    ll ans = 1;
    ll d = 1;
    for (int k = 0; k < K; k++) {
        cout << ans << endl;
        if (f(ans + d) + EPS >= f(ans + d * 10)) {
            d *= 10;
        }
        ans += d;
    }
}

int main() {
    cin >> K;

    solve();

    return 0;
}
