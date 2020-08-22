/*
[abc150] F - Xor Shift
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;
const int MAX_B = 30;

const int MAX_PAT = MAX_N;
const int MAX_TXT = MAX_N * 2;

typedef bitset<MAX_B> BS;

int N;
BS a[MAX_N], b[MAX_N];

int table[MAX_PAT + 1];
bool matched[MAX_TXT];

void kmp(const vector<BS> &txt, const vector<BS> &pat) {
    int n = txt.size(), m = pat.size();

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

void solve() {
    vector<BS> c(2 * N), d(N);
    for (int i = 0; i < 2 * N; i++) {
        c[i] = a[i % N] ^ a[(i + 1) % N];
    }
    for (int i = 0; i < N; i++) {
        d[i] = b[i % N] ^ b[(i + 1) % N];
    }

    kmp(c, d);

    for (int i = 0; i < N; i++) {
        if (!matched[i]) {
            continue;
        }
        int x = (a[i] ^ b[0]).to_ulong();
        cout << i << " " << x << endl;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int ai;
        cin >> ai;
        a[i] = BS(ai);
    }
    for (int i = 0; i < N; i++) {
        int bi;
        cin >> bi;
        b[i] = BS(bi);
    }

    solve();

    return 0;
}
