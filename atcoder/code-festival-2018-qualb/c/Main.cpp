/*
[code-festival-2018-qualb] C - Special Cake for CODE FESTIVAL
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

const int MAX_N = 1000;

int N;
bool ans[MAX_N + 2][MAX_N + 2];

void check(int i, int j) {
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};
    bool ok = ans[i][j];
    for (int k = 0; k < 4; k++) {
        ok = ok || ans[i + di[k]][j + dj[k]];
    }
    if (!ok) {
        ans[i][j] = true;
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans[i][j] = ((i * 2 + j) % 5 == 0);
        }
    }

    for (int i = 1; i <= N; i++) {
        check(i, 1);
        check(i, N);
    }
    for (int j = 1; j <= N; j++) {
        check(1, j);
        check(N, j);
    }
}

int main() {
    cin >> N;

    solve();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << (ans[i][j] ? 'X' : '.');
        }
        cout << endl;
    }

    return 0;
}
