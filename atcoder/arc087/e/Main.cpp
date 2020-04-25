/*
[arc087] E - Prefix-free Game
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

struct Node {
    int ch[2] = {-1, -1};
};

int N;
ll L;
string S[MAX_N];
vector<Node> tree;

void add(string &s, int k = 0, int v = 0) {
    if (k >= (int)s.size()) {
        return;
    }
    Node &nd = tree[v];
    int ci = s[k] == '0' ? 0 : 1;
    int nv = nd.ch[ci];
    if (nv == -1) {
        nv = nd.ch[ci] = tree.size();
        tree.push_back(Node());
    }
    add(s, k + 1, nv);
}

ll grundy(ll n) { return n & (-n); }

ll dfs(int v = 0, int d = 0) {
    if (v == -1) {
        return 0;
    }
    ll ret = 0;
    if ((tree[v].ch[0] == -1) != (tree[v].ch[1] == -1)) {
        ret ^= grundy(L - d);
    }
    for (int i = 0; i < 2; i++) {
        ret ^= dfs(tree[v].ch[i], d + 1);
    }
    return ret;
}

bool solve() {
    tree.push_back(Node());
    for (int i = 0; i < N; i++) {
        add(S[i]);
    }

    return dfs();
}

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    cout << (solve() ? "Alice" : "Bob") << endl;

    return 0;
}
