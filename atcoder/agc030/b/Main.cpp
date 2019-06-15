/*
[agc030] B - Tree Burning
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

const int MAX_N = 2e5;

ll L;
int N;
ll X[MAX_N];
ll s[MAX_N + 1];

ll solve() {
    ll ans = 0;
    for (int k = 0; k < 2; k++) {
        s[0] = 0;
        for (int i = 0; i < N; i++) {
            s[i + 1] = s[i] + X[i];
        }

        for (int i = 0; i < N; i++) {
            int t = (N + i - 1) / 2 + 1;
            ll c = (s[t] - s[i] + L * (N - t) - s[N] + s[t]) * 2 -
                   (((N - i) % 2 == 0) ? (L - X[t]) : X[t - 1]);
            ans = max(ans, c);
        }

        for (int i = 0; i < N; i++) {
            X[i] = L - X[i];
        }
        reverse(X, X + N);
    }
    return ans;
}

int main() {
    cin >> L >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    cout << solve() << endl;

    return 0;
}
