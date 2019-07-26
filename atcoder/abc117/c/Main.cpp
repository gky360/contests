/*
[abc117] C - Streamline
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
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
typedef pair<ll, ll> pll;

const int MAX_M = 1e5;

int N, M;
int X[MAX_M];

ll solve() {
    sort(X, X + M);

    int d[MAX_M];
    for (int i = 0; i < M - 1; i++) {
        d[i] = X[i + 1] - X[i];
    }
    sort(d, d + M - 1);

    ll ans = 0;
    for (int i = 0; i < M - N; i++) {
        ans += d[i];
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }

    cout << solve() << endl;

    return 0;
}
