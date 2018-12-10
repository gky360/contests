/*
[arc098] D - Xor Sum 2
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

const int MAX_N = 200000;

int N;
ll a[MAX_N + 1];

ll solve() {
    ll ans = 0;
    int r = 0;
    ll sum_p = 0, sum_x = 0;
    for (int l = 0; l < N + 1; l++) {
        for (; sum_p == sum_x && r < N + 1; r++) {
            sum_p += a[r];
            sum_x ^= a[r];
        }
        ans += r - l - 1;
        sum_p -= a[l];
        sum_x ^= a[l];
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    a[N] = -1LL;

    cout << solve() << endl;

    return 0;
}
