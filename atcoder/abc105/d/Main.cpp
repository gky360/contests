/*
[abc105] D - Candy Distribution
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

int N, M;
int a[MAX_N];

ll solve() {
    map<int, int> cnt;
    int s = 0;
    cnt[0]++;
    for (int i = 0; i < N; i++) {
        (s += a[i]) %= M;
        cnt[s]++;
    }

    ll ans = 0;
    for (auto &kv : cnt) {
        ll v = kv.second;
        ans += v * (v - 1) / 2;
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
