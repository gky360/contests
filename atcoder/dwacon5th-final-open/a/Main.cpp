/*
[dwacon5th-final-open] A - Taro vs. Jiro
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

const int MAX_N = 1e5;

string s;
int N, M;
ll K;
vector<int> g[MAX_N];
bool dp[3][MAX_N];

void solve() {
    for (int i = 0; i < N; i++) {
        dp[0][i] = (s[i] == 'B');
    }

    int t = (K % 2 == 0) ? 2 : 1;
    for (int k = 1; k <= t; k++) {
        bool is_taro = (K - k) % 2 == 0;
        for (int i = 0; i < N; i++) {
            bool has_any = false;
            for (int to : g[i]) {
                if (dp[k - 1][to] == is_taro) {
                    has_any = true;
                }
            }
            dp[k][i] = (is_taro == has_any);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << (dp[t][i] ? "First" : "Second") << endl;
    }
}

int main() {
    cin >> N >> M >> K;
    cin >> s;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    solve();

    return 0;
}
