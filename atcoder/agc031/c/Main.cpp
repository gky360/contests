/*
[agc031] C - Differ by 1 Bit
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int N, A, B;

int count(int x) {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (x & (1 << i)) {
            ret++;
        }
    }

    return ret;
}

void dfs(int a, int b, int s, int l, int mask, int pat, vector<int> &ans) {
    if (l == 1) {
        ans[s] = a | pat;
        ans[s + 1] = b | pat;
        return;
    }

    int p = -(a ^ b) & (a ^ b);
    int m = mask ^ p;
    int v = -m & m;

    dfs((a & m), (a & m) ^ v, s, l - 1, m, pat | (a & p), ans);
    dfs((a & m) ^ v, (b & m), s + (1 << (l - 1)), l - 1, m, pat | (b & p), ans);
}

void solve() {
    if (count(A) % 2 == count(B) % 2) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    vector<int> ans(1 << N);
    dfs(A, B, 0, N, (1 << N) - 1, 0, ans);

    for (int i = 0; i < (1 << N); i++) {
        cout << ans[i];
        if (i == (1 << N) - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}

int main() {
    cin >> N >> A >> B;

    solve();

    return 0;
}
