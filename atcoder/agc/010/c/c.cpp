// AtCoder Grand Contest 010
// C - Cleaning

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100000;

int N;
vector<int> G[MAX_N];
ll a[MAX_N];

ll dfs(int v, int par = -1) {
    ll down, down_max, down_sum, p, p_max;

    if (G[v].size() == 1) {
        if (par == -1) {
            return (dfs(G[v][0], v) == a[v] ? 0 : -1);
        } else {
            return a[v];
        }
    }

    down_max = 0;
    down_sum = 0;
    for (int to : G[v]) {
        if (to == par) {
            continue;
        }
        down = dfs(to, v);
        if (down < 0) {
            return -1;
        }
        down_max = max(down_max, down);
        down_sum += down;
    }
    p = down_sum - a[v];
    p_max = min(down_sum - down_max, down_sum / 2);
    if (!(0 <= p && p <= p_max)) {
        return -1;
    }
    return 2 * a[v] - down_sum;
}

int main() {

    int x, y;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    cout << (dfs(0) == 0 ? "YES" : "NO") << endl;

    return 0;

}



