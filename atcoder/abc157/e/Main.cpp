/*
[abc157] E - Simple String Queries
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int Z = 26;

int N;
string S;
int Q;
set<int> pos[Z];

void solve() {
    for (int i = 0; i < N; i++) {
        pos[S[i] - 'a'].insert(i);
    }
    for (int x = 0; x < Z; x++) {
        pos[x].insert(N);
    }

    for (int q = 0; q < Q; q++) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            int p;
            char c;
            cin >> p >> c;
            p--;
            for (int x = 0; x < Z; x++) {
                pos[x].erase(p);
            }
            pos[c - 'a'].insert(p);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;

            int ans = 0;
            for (int x = 0; x < Z; x++) {
                if (*(pos[x].lower_bound(l)) <= r) {
                    ans++;
                }
            }

            cout << ans << endl;
        }
    }
    return;
}

int main() {
    cin >> N;
    cin >> S;
    cin >> Q;

    solve();

    return 0;
}
