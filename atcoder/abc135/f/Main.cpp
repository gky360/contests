/*
[abc135] F - Strings of Eternity
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_S = 5e5;
const int MAX_T = 5e5;

const int MAX_TXT = 2 * MAX_S + MAX_T;
const int MAX_PAT = MAX_T;

string txt, pat;
int table[MAX_PAT + 1];
bool matched[MAX_TXT];

void kmp() {
    int n = txt.length(), m = pat.length();

    table[0] = -1;
    for (int i = 0, j = -1; i < m; i++) {
        while (j >= 0 && pat[i] != pat[j]) {
            j = table[j];
        }
        table[i + 1] = ++j;
    }

    for (int i = 0, j = 0; i < n; i++) {
        while (j >= 0 && txt[i] != pat[j]) {
            j = table[j];
        }
        if (++j >= m) {
            matched[i - m + 1] = true;
            j = table[j];
        }
    }
}

string s, t;
int dep[MAX_S];
bool looped;

int dfs(int v, int h = 0) {
    if (h > (int)s.length()) {
        looped = true;
        return 0;
    }
    if (dep[v] >= 0) {
        return dep[v];
    }
    if (matched[v]) {
        return (dep[v] = 1 + dfs((v + t.length()) % s.length(), h + 1));
    }
    return (dep[v] = 0);
}

ll solve() {
    pat = t;
    while (txt.length() < s.length() + t.length()) {
        txt += s;
    }
    kmp();

    memset(dep, -1, sizeof(dep));
    int ans = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        ans = max(ans, dfs(i));
        if (looped) {
            return -1;
        }
    }

    return ans;
}

int main() {
    cin >> s;
    cin >> t;

    cout << solve() << endl;

    return 0;
}
