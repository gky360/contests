/*
[abc122] C - GeT AC
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int MAX_Q = 1e5;

int N, Q;
string S;
int l[MAX_Q], r[MAX_Q];
int c[MAX_N];

void solve() {
    for (int i = 1; i < N; i++) {
        c[i] = c[i - 1];
        if (S[i - 1] == 'A' && S[i] == 'C') {
            c[i]++;
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << c[r[i]] - c[l[i]] << endl;
    }
}

int main() {
    cin >> N >> Q;
    cin >> S;
    for (int i = 0; i < Q; i++) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }

    solve();

    return 0;
}
