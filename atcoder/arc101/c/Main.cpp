/*
[arc101] C - Candles
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

int N, K;
int x[MAX_N];

ll solve() {
    int ans = 1e9;
    for (int i = 0; i + K <= N; i++) {
        if (x[i] < 0 && x[i + K - 1] < 0) {
            ans = min(ans, -x[i]);
        } else if (x[i] < 0 && x[i + K - 1] >= 0) {
            if (-x[i] > x[i + K - 1]) {
                ans = min(ans, -x[i] + 2 * x[i + K - 1]);
            } else {
                ans = min(ans, -2 * x[i] + x[i + K - 1]);
            }
        } else {
            ans = min(ans, x[i + K - 1]);
        }
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    cout << solve() << endl;

    return 0;
}
