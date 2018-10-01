/*
[agc024] C - Sequence Growing Easy
*/

#include <algorithm>
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

int N;
ll a[MAX_N];

ll solve() {
    ll cnt[MAX_N];
    memset(cnt, 0, sizeof(cnt));

    if (a[0] > 0) {
        return -1;
    }
    for (int i = 1; i < N; i++) {
        if (a[i] - a[i - 1] > 1) {
            return -1;
        }
        if (a[i] > i) {
            return -1;
        }
        cnt[i - a[i]] = max(cnt[i - a[i]], a[i]);
    }

    return accumulate(cnt, cnt + N, 0LL);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
