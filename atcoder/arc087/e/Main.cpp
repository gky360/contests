// ARC087
// E - Prefix-free Game

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;

struct node {
    int child[2] = {-1, -1};
};

int N;
ll L;
vector<node> tree;

void add(string &s, int k = 0, int v = 0) {
    if (k >= (int)s.size()) {
        return;
    }
    node &nd = tree[v];
    int next_i = s[k] == '0' ? 0 : 1;
    int next_v = nd.child[next_i];
    if (next_v == -1) {
        next_v = nd.child[next_i] = tree.size();
        tree.push_back(node());
    }
    add(s, k + 1, next_v);
    return;
}

ll grundy(ll a) { return a & (-a); }

ll dfs(int v = 0, ll d = 0) {
    if (v == -1) {
        return 0;
    }
    ll ret = 0;
    if ((tree[v].child[0] == -1) != (tree[v].child[1] == -1)) {
        ret = grundy(L - d);
    }
    for (int i = 0; i < 2; i++) {
        ret ^= dfs(tree[v].child[i], d + 1);
    }
    return ret;
}

int main() {
    cin >> N >> L;
    tree.push_back(node());
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        add(s);
    }

    cout << (dfs() != 0 ? "Alice" : "Bob") << endl;

    return 0;
}
