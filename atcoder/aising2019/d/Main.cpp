/*
[aising2019] D - Nearest Card Game
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

const int MAX_N = 1e5;
const int MAX_Q = 1e5;

int N, Q;
int A[MAX_N];
int X[MAX_Q];
ll s1[MAX_N + 1], s2[MAX_N + 1];

ll query(int x) {
    int ng = -1;
    int ok = N;

    while (ok - ng > 1) {
        int m = (ok + ng) / 2;
        if (A[N - (m + 1) / 2 - 1] - x < x - A[N - m - 1]) {
            ok = m;
        } else {
            ng = m;
        }
    }

    return s1[N] - s1[N - (ok + 1) / 2] +
           (N % 2 == 0 ? s1[N - ok] - s2[N - ok] : s2[N - ok]);
}

void solve() {
    s1[0] = s2[0] = 0;
    for (int i = 0; i < N; i++) {
        s1[i + 1] += s1[i] + A[i];
        s2[i + 1] += s2[i] + (i % 2 == 0 ? A[i] : 0);
    }

    for (int i = 0; i < Q; i++) {
        cout << query(X[i]) << endl;
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < Q; i++) {
        cin >> X[i];
    }

    solve();

    return 0;
}
