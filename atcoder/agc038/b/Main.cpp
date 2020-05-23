/*
[agc038] B - Sorting a Segment
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 200000;

int N, K;
int P[MAX_N];
vector<int> g[MAX_N];
bool visited[MAX_N];

void dfs(int v) {
    if (visited[v]) {
        return;
    }
    visited[v] = true;
    for (int to : g[v]) {
        dfs(to);
    }
}

ll solve() {
    int ord = 1, pre = -1;
    for (int i = 1; i < N; i++) {
        ord = (P[i - 1] < P[i]) ? ord + 1 : 1;
        if (ord >= K) {
            if (pre != -1) {
                int u = pre - K + 1;
                int v = i - K + 1;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            pre = i;
        }
    }

    set<int> s;
    for (int i = 0; i < K; i++) {
        s.insert(P[i]);
    }
    for (int i = 0; i + K < N; i++) {
        s.insert(P[i + K]);
        if (P[i] == *s.begin() && P[i + K] == *s.rbegin()) {
            g[i].push_back(i + 1);
            g[i + 1].push_back(i);
        }
        s.erase(P[i]);
    }

    int ans = 0;
    for (int i = 0; i + K <= N; i++) {
        if (!visited[i]) {
            ans++;
        }
        dfs(i);
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    cout << solve() << endl;

    return 0;
}
