/*
[dwacon5th-prelims] E - Cyclic GCDs
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
const ll MOD = 998244353;

int N;
int a[MAX_N];

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(a %= b, b);
    }
    return a;
}

ll solve() {
    sort(a, a + N);
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        (ans *= gcd(a[i], i)) %= MOD;
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
