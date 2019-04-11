/*
[abc114] C - 755
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
int t[] = {7, 5, 3};

bool is_ok(ll n) {
    bool has_t[10];
    memset(has_t, 0, sizeof(has_t));
    for (; n > 0; n /= 10) {
        has_t[n % 10] = true;
    }
    bool ret = true;
    for (int d : t) {
        ret = ret && has_t[d];
    }
    return ret;
}

int dfs(ll n) {
    if (n > N) {
        return 0;
    }

    int cnt = is_ok(n) ? 1 : 0;
    for (int d : t) {
        cnt += dfs(n * 10 + d);
    }

    return cnt;
}

ll solve() { return dfs(0); }

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
