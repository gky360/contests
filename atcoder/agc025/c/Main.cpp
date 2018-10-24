/*
[agc025] C - Interval Game
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
const int C = MAX_N;

int N;
int l[MAX_N], r[MAX_N];
int sl[2 * MAX_N + 1], sr[2 * MAX_N + 1];

ll solve() {
    sl[C]++;
    sr[C]++;
    for (int i = 0; i < N; i++) {
        sl[C + r[i]]++;
        sr[C + l[i]]++;
    }
    for (int i = 1; i <= 2 * C; i++) {
        sl[i] += sl[i - 1];
    }
    for (int i = 2 * C - 1; i >= 0; i--) {
        sr[i] += sr[i + 1];
    }

    ll ans = 0;
    for (int i = 0; i < 2 * C; i++) {
        ans += min(sl[i], sr[i + 1]) * 2;
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> l[i] >> r[i];
    }

    cout << solve() << endl;

    return 0;
}
