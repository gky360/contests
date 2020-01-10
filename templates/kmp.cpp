// KMP法

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_TXT = 1e5;
const int MAX_PAT = 1e4;

int table[MAX_PAT + 1];
bool matched[MAX_TXT];

void kmp(const string &txt, const string &pat) {
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

int main() {
    kmp("ABABABCABAAB", "ABABCA");
    return 0;
}
