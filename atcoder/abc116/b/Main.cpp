/*
[abc116] B - Collatz Problem
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

int s;
map<int, int> m;

ll solve() {
    m[s] = 1;
    int a = s;
    for (int i = 2; i <= 1000000; i++) {
        a = (a % 2 == 0) ? a / 2 : 3 * a + 1;
        if (m[a] > 0) {
            return i;
        }
        m[a] = i;
    }
    return -1;
}

int main() {
    cin >> s;

    cout << solve() << endl;

    return 0;
}
