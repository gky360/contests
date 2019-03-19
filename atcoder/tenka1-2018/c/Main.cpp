/*
[tenka1-2018] C - Align
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

int N;
int a[MAX_N];

ll solve() {
    sort(a, a + N);

    ll ans = 0;
    if (N % 2 == 0) {
        // -2, -2, ..., -1, 1, 2, 2, ..., 2
        for (int i = 0; i < N / 2 - 1; i++) {
            ans += -2 * a[i] + 2 * a[N - i - 1];
        }
        ans += -a[N / 2 - 1] + a[N / 2];
    } else {
        ll ans1 = 0, ans2 = 0;
        // -2, -2, ..., -2, -1, -1, 2, 2, ..., 2
        for (int i = 0; i < N / 2; i++) {
            ans1 += -2 * a[i] + 2 * a[N - i - 1];
        }
        ans1 += a[N / 2 - 1] - a[N / 2];

        // -2, -2, ..., -2, 1, 1, 2, 2, ..., 2
        for (int i = 0; i < N / 2; i++) {
            ans2 += -2 * a[i] + 2 * a[N - i - 1];
        }
        ans2 += a[N / 2] - a[N / 2 + 1];

        ans = max(ans1, ans2);
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
