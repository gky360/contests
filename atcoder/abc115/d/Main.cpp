/*
[abc115] D - Christmas
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

int N;
ll X;

ll count(int level, ll idx) {
    if (level == 0) {
        return idx;
    }
    ll len = (1LL << (level + 2)) - 3;
    if (idx == 0) {
        return 0;
    }
    if (idx <= len / 2) {
        return count(level - 1, idx - 1);
    }
    if (idx < len) {
        return (1LL << (level)) - 1 + 1 + count(level - 1, idx - len / 2 - 1);
    }
    return (1LL << (level + 1)) - 1;
}

ll solve() { return count(N, X); }

int main() {
    cin >> N >> X;

    cout << solve() << endl;

    return 0;
}
