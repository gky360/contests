/*
[abc100] B - Ringo's Favorite Numbers
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

int D, N;

ll solve() {
    int ans = 1;
    for (int i = 0; i < D; i++) {
        ans *= 100;
    }
    ans *= (N == 100 ? 101 : N);
    return ans;
}

int main() {
    cin >> D >> N;

    cout << solve() << endl;

    return 0;
}
