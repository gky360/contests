// ARC095
// E - Symmetric Grid

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_H = 12;
const int MAX_W = 12;

int H, W;
int perm[MAX_W];
string s[MAX_H];

bool same(string a, string b) {
    reverse(b.begin(), b.end());
    return a == b;
}

bool check() {
    vector<string> ss(H);

    for (int j = 0; j < H; j++) {
        ss[j] = string(W, ' ');
        for (int i = 0; i < W; i++) {
            ss[j][i] = s[j][perm[i]];
        }
    }

    int odd_cnt = 0;
    vector<bool> used(H);
    for (int i = 0; i < H; i++) {
        if (used[i]) {
            continue;
        }
        used[i] = true;
        bool is_found = false;
        for (int j = i + 1; j < H; j++) {
            if (!used[j] && same(ss[i], ss[j])) {
                is_found = true;
                used[j] = true;
                break;
            }
        }
        if (!is_found) {
            if (H % 2 == 0 || odd_cnt >= 1) {
                return false;
            }
            odd_cnt++;
        }
    }

    return true;
}

bool dfs(int x, int b) {
    if (b == 0) {
        return check();
    }

    int li, ri;
    for (li = 0; li < W; li++) {
        if ((b >> li) & 1) {
            break;
        }
    }
    for (ri = li + 1; ri < W; ri++) {
        if ((b >> ri) & 1) {
            perm[x] = li;
            perm[W - 1 - x] = ri;
            if (dfs(x + 1, b - (1 << li) - (1 << ri))) {
                return true;
            }
        }
    }

    return false;
}

bool solve() {
    if (W % 2 == 0) {
        return dfs(0, (1 << W) - 1);
    }
    for (int k = 0; k < W; k++) {
        perm[W / 2] = k;
        if (dfs(0, (1 << W) - 1 - (1 << k))) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> s[i];
    }

    cout << (solve() ? "YES" : "NO") << endl;

    return 0;
}
