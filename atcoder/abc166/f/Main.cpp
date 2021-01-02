/*
[abc166] F - Three Variables Game
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N, A, B, C;
int s[MAX_N];
int ans[MAX_N];

int to_i(string &si) {
    if (si == "AB") return 0;
    if (si == "BC") return 1;
    return 2;
}

bool solve() {
    int n[3] = {A, B, C};
    for (int i = 0; i < N; i++) {
        int p = s[i], q = (p + 1) % 3;
        if (n[p] + n[q] == 0) {
            return false;
        }
        if (n[p] == 0 || n[q] == 0) {
            if (n[p] == 0) swap(p, q);
        } else if (i + 1 < N && s[i + 1] != s[i]) {
            if (q == (s[i + 1] + 2) % 3) swap(p, q);
        }
        n[p]--, n[q]++;
        ans[i] = q;
    }
    return true;
}

int main() {
    cin >> N >> A >> B >> C;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        s[i] = to_i(str);
    }

    if (solve()) {
        cout << "Yes" << endl;
        for (int i = 0; i < N; i++) {
            cout << char('A' + ans[i]) << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}
