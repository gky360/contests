/*
[dwacon5th-prelims] A - Thumbnail
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

const int MAX_N = 100;

int N;
int a[MAX_N];

int solve() {
    double avg = 0;
    for (int i = 0; i < N; i++) {
        avg += a[i];
    }
    avg /= N;

    int ans = -1;
    double val = 1000;
    for (int i = 0; i < N; i++) {
        double tmp = abs(1.0 * a[i] - avg);
        if (val > tmp) {
            val = tmp;
            ans = i;
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
