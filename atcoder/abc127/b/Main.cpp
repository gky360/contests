/*
[abc127] B - Algae
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

int r, D, x;

void solve() {
    for (int i = 0; i < 10; i++) {
        x = r * x - D;
        cout << x << endl;
    }
}

int main() {
    cin >> r >> D >> x;

    solve();

    return 0;
}
