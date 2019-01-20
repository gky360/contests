/*
[abc103] A - Task Scheduling Problem
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

const int MAX_N = 3;

int a[3];

ll solve() {
    sort(a, a + MAX_N);
    return a[2] - a[0];
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
