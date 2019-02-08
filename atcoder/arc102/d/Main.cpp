/*
[arc102] D - All Your Paths are Different Lengths
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

const int MAX_N = 20;

int L;

void solve() {
    int n = 0;
    while ((1 << n) <= L) {
        n++;
    }
    int m = (n - 1) * 2;

    int paths[MAX_N];
    fill(paths, paths + n, -1);
    int done_l = (1 << (n - 1));
    for (int i = n - 1; i > 0; i--) {
        int b = 1 << (i - 1);
        if (L & b) {
            m++;
            paths[i] = done_l;
            done_l = done_l | b;
        }
    }

    int pow2 = 1;
    cout << n << " " << m << endl;
    for (int i = 1; i < n; i++) {
        cout << i << " " << i + 1 << " " << 0 << endl;
        cout << i << " " << i + 1 << " " << pow2 << endl;
        pow2 *= 2;
        if (paths[i] >= 0) {
            cout << i << " " << n << " " << paths[i] << endl;
        }
    }
}

int main() {
    cin >> L;

    solve();

    return 0;
}
