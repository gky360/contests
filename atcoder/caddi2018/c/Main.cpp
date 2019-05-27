/*
[caddi2018] C - Product and GCD
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

ll N, P;

ll solve() {
    map<ll, int> fac;
    ll p = P;
    for (ll d = 2; d * d <= P; d++) {
        while (p % d == 0) {
            fac[d]++;
            p /= d;
        }
    }
    if (p > 0) {
        fac[p]++;
    }

    ll ans = 1;
    for (auto &kv : fac) {
        ll d = kv.first;
        int cnt = kv.second;
        while (cnt >= N) {
            ans *= d;
            cnt -= N;
        }
    }

    return ans;
}

int main() {
    cin >> N >> P;

    cout << solve() << endl;

    return 0;
}
