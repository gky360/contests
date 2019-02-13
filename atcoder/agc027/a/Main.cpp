/*
[agc027] A - Candy Distribution Again
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

const int MAX_N = 100;

int N, x;
int a[MAX_N];

ll solve() {
    sort(a, a + N);
    ll s = 0;
    for (int i = 0; i < N; i++) {
        s += a[i];
        if (s > x) {
            return i;
        }
    }
    return (s == x ? N : (N - 1));
}

int main() {
    cin >> N >> x;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
