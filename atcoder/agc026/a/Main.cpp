/*
[agc026] A - Colorful Slimes 2
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
vector<int> a;

int solve() {
    int prev_color = -1;
    int prev_i = -1;
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        if (a[i] == prev_color) {
            continue;
        }
        ans += (i - prev_i) / 2;
        prev_color = a[i];
        prev_i = i;
    }
    return ans;
}

int main() {
    cin >> N;
    a.resize(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    a[N] = -1;

    cout << solve() << endl;

    return 0;
}
