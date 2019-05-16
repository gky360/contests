/*
[agc029] D - Grid game
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

const int MAX_N = 2e5;
const int MAX_H = 2e5;

int H, W, N;
int X[MAX_N], Y[MAX_N];
set<int> obs[MAX_H];

ll solve() {
    for (int i = 0; i < N; i++) {
        obs[Y[i]].insert(X[i] - Y[i]);
    }

    int ans = H;
    int lx = 0;
    for (int y = 0; y < W; y++) {
        obs[y].insert(H - y);
        while (obs[y].find(lx) != obs[y].end()) {
            lx++;
        }
        auto iter = obs[y].upper_bound(lx);
        if (iter == obs[y].end()) {
            break;
        }
        int x = *iter;
        ans = min(ans, x + y);
    }

    return ans;
}

int main() {
    cin >> H >> W >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        X[i]--;
        Y[i]--;
    }

    cout << solve() << endl;

    return 0;
}
