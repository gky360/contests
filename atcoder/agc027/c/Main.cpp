/*
[agc027] C - ABland Yard
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

const int MAX_N = 200000;

int N, M;
int s[MAX_N];
set<int> g[MAX_N];
int cnt[MAX_N][2];
bool removed[MAX_N];

bool solve() {
    queue<int> q;
    for (int u = 0; u < N; u++) {
        for (int v : g[u]) {
            cnt[u][s[v]]++;
        }
        if (cnt[u][0] == 0 || cnt[u][1] == 0) {
            q.push(u);
        }
    }

    int remain = N;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (removed[u]) {
            continue;
        }
        removed[u] = true;
        remain--;

        for (int v : g[u]) {
            if (u == v) {
                continue;
            }
            g[v].erase(u);
            cnt[v][s[u]]--;
            if (cnt[v][0] == 0 || cnt[v][1] == 0) {
                q.push(v);
            }
        }
    }

    return remain > 0;
}

int main() {
    string s_str;
    cin >> N >> M;
    cin >> s_str;
    for (int i = 0; i < N; i++) {
        s[i] = (s_str[i] == 'A') ? 0 : 1;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].insert(b);
        g[b].insert(a);
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
