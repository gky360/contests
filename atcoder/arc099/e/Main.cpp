/*
[arc099] E - Independence
*/

#include <algorithm>
#include <bitset>
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

const int MAX_N = 700;

int N, M;
bool g[MAX_N][MAX_N];
int colors[MAX_N];
int cnt[2];

bool dfs(int n, int color = 0) {
    if (colors[n] != -1) {
        return colors[n] == color;
    }
    colors[n] = color;
    cnt[color]++;

    bool ret = true;
    for (int i = 0; i < N; i++) {
        if (g[n][i]) {
            ret = ret && dfs(i, color ^ 1);
        }
    }
    return ret;
}
