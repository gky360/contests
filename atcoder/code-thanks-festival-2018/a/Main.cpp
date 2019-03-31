/*
[code-thanks-festival-2018] A - Two Problems
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

int T, A, B, C, D;

int solve() {
    int ans = 0;
    if (A + C <= T) {
        ans = max(ans, B + D);
    }
    if (A <= T) {
        ans = max(ans, B);
    }
    if (C <= T) {
        ans = max(ans, D);
    }
    return ans;
}

int main() {
    cin >> T >> A >> B >> C >> D;

    cout << solve() << endl;

    return 0;
}
