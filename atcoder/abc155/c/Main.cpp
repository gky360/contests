/*
[abc155] C - Poll
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;

int N;
string S[MAX_N];
map<string, int> m;

void solve() {
    int ma = 0;
    for (int i = 0; i < N; i++) {
        m[S[i]]++;
        ma = max(ma, m[S[i]]);
    }

    for (auto &p : m) {
        string s = p.first;
        int c = p.second;
        if (c == ma) {
            cout << s << endl;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    solve();

    return 0;
}
