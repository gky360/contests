/*
[abc116] C - Grand Garden
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

const int MAX_N = 100;

int N;
int h[MAX_N];

ll solve() {
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < N; i++) {
        if (h[i] > cur) {
            ans += h[i] - cur;
        }
        cur = h[i];
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    cout << solve() << endl;

    return 0;
}
