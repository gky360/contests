/*
[caddi2018] E - Negative Doubling
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
const int K = 16;

int N;
ll A[MAX_N];
ll dp0[MAX_N][K], dp1[MAX_N][K];

ll solve() {
    for (int k = 0; k < K; k++) {
        dp0[N - 1][k] = k;
        dp1[0][k] = k;
    }

    for (int i = N - 2; i >= 0; i--) {
        ll k4 = 1;
        for (int k = 0; k < K; k++) {
            int j = 0;
            ll j4 = 1;
            while (A[i] * k4 > A[i + 1] * j4) {
                j++;
                j4 *= 4;
            }
            if (j <= 15) {
                dp0[i][k] = dp0[i + 1][j] + k;
            } else {
                dp0[i][k] = dp0[i + 1][15] + (N - i - 1) * (j - 15) + k;
            }

            k4 *= 4;
        }
    }

    for (int i = 1; i < N; i++) {
        ll k4 = 1;
        for (int k = 0; k < K; k++) {
            int j = 0;
            ll j4 = 1;
            while (A[i - 1] * j4 < A[i] * k4) {
                j++;
                j4 *= 4;
            }
            if (j <= 15) {
                dp1[i][k] = dp1[i - 1][j] + k;
            } else {
                dp1[i][k] = dp1[i - 1][15] + i * (j - 15) + k;
            }

            k4 *= 4;
        }
    }

    ll ans = dp0[0][0] * 2;
    for (int i = 1; i < N; i++) {
        ans = min(ans, i + dp1[i - 1][0] * 2 + dp0[i][0] * 2);
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
