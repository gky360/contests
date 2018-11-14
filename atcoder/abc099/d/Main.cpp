/*
[abc099] D - Good Grid
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

const int MAX_N = 500;
const int MAX_C = 30;
const int K = 3;
const int INF = 1e9;

int N, C;
int d[MAX_C][MAX_C];
int c[MAX_N][MAX_N];
int pat[K];
bool used[MAX_C];
int cnt[K][MAX_C];

int calc() {
    int sum_d = 0;
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < C; i++) {
            sum_d += d[i][pat[k]] * cnt[k][i];
        }
    }
    return sum_d;
}

int dfs(int k) {
    if (k >= K) {
        return calc();
    }

    int ans = INF;
    for (int i = 0; i < C; i++) {
        if (used[i]) {
            continue;
        }
        used[i] = true;
        pat[k] = i;
        ans = min(ans, dfs(k + 1));
        used[i] = false;
    }
    return ans;
}

int solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cnt[(i + j) % K][c[i][j]]++;
        }
    }

    return dfs(0);
}

int main() {
    cin >> N >> C;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    cout << solve() << endl;

    return 0;
}
