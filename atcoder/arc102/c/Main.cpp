/*
[arc102] C - Triangular Relationship
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

int N, K;

ll solve() {
    ll d = N / K;
    ll ans = d * d * d;
    if (K % 2 == 0) {
        d = (N + K / 2) / K;
        ans += d * d * d;
    }

    return ans;
}

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
