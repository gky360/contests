// AtCoder Grand Contest 014
// D - Black and White Tree

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100000;

int N;
vector<int> G[MAX_N];
int match[MAX_N];
bool used[MAX_N];

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;

    for (int u : G[v]) {
        if (match[u] < 0 || dfs(match[u])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }

    return false;
}

int bipartite_matching() {
    int res = 0;
    memset(match, -1, sizeof(match));
    for (int v = 0; v < N; v++) {
        if (match[v] >= 0) {
            continue;
        }
        memset(used, 0, sizeof(used));
        if (dfs(v)) {
            res++;
        }
    }
    return res;
}


int main() {

    int a, b;

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cout << (bipartite_matching() * 2 == N ? "Second" : "First") << endl;

    return 0;

}



