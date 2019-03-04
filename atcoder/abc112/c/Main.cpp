/*
[abc112] C - Pyramid
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
typedef tuple<int, int, int> tiii;

const int MAX_N = 100;
const int MAX_X = 100;
const int MAX_Y = 100;

int N;
int x[MAX_N], y[MAX_N];
int h[MAX_N];

bool can(int s, int t, int ans_h) {
    for (int i = 0; i < N; i++) {
        if (h[i] != max(0, ans_h - abs(x[i] - s) - abs(y[i] - t))) {
            return false;
        }
    }
    return true;
}

tiii solve() {
    int n;
    for (n = 0; n < N; n++) {
        if (h[n] > 0) {
            break;
        }
    }
    for (int s = 0; s <= MAX_X; s++) {
        for (int t = 0; t <= MAX_Y; t++) {
            int ans_h = abs(x[n] - s) + abs(y[n] - t) + h[n];
            if (can(s, t, ans_h)) {
                return tiii(s, t, ans_h);
            }
        }
    }
    return tiii(-1, -1, -1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> h[i];
    }

    tiii ans = solve();
    cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << endl;

    return 0;
}
