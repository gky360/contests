/*
[aising2019] C - Alternating Path
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

const int MAX_H = 400;
const int MAX_W = 400;

int H, W;
string S[MAX_H];
bool visited[MAX_H][MAX_W];

int dh[4] = {-1, 0, 1, 0};
int dw[4] = {0, 1, 0, -1};

pii dfs(int h, int w) {
    if (visited[h][w]) {
        return {0, 0};
    }
    visited[h][w] = true;

    pii ret = ((S[h][w] == '#') ? pii{1, 0} : pii{0, 1});
    for (int k = 0; k < 4; k++) {
        if (0 <= h + dh[k] && h + dh[k] < H && 0 <= w + dw[k] &&
            w + dw[k] < W && S[h + dh[k]][w + dw[k]] != S[h][w]) {
            pii p = dfs(h + dh[k], w + dw[k]);
            ret.first += p.first;
            ret.second += p.second;
        }
    }

    return ret;
}

ll solve() {
    ll ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            pii p = dfs(i, j);
            ans += 1LL * p.first * p.second;
        }
    }

    return ans;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    cout << solve() << endl;

    return 0;
}
