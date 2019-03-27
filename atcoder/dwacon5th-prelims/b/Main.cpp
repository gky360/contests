/*
[dwacon5th-prelims] B - Sum AND Subarrays
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

const int MAX_N = 1000;
const int D = 40;

int N, K;
int a[MAX_N];

ll solve() {
    ll s[MAX_N + 1];
    s[0] = 0;
    for (int i = 1; i <= N; i++) {
        s[i] = s[i - 1] + a[i - 1];
    }

    vector<ll> bu;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            bu.push_back(s[j] - s[i]);
        }
    }

    ll ans = 0;
    for (int d = D; d >= 0; d--) {
        ll x = ans | (1LL << d);
        int cnt = 0;
        for (ll b : bu) {
            if ((x & b) == x) {
                cnt++;
            }
        }
        if (cnt >= K) {
            ans = x;
        }
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
