/*
[code-thanks-festival-2018] B - Colored Balls
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

int X, Y;

bool solve() {
    if (X < Y) {
        swap(X, Y);
    }
    int d = X - Y;
    int rx = X - 3 * d / 2, ry = Y - d / 2;
    return (d % 2 == 0) && rx >= 0 && ry >= 0 && (rx % 4 == 0) && (ry % 4 == 0);
}

int main() {
    cin >> X >> Y;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
