/*
[code-thanks-festival-2018] C - Pair Distance
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

const int MAX_N = 1e5;

int N;
int x[MAX_N];

ll solve() {
    sort(x, x + N);

    ll ans = 0;
    ll s = 0;
    for (int i = 0; i < N; i++) {
        ans += 1LL * i * x[i] - s;
        s += x[i];
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    cout << solve() << endl;

    return 0;
}
