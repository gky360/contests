/*
[panasonic2020] D - String Equivalence
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;

void dfs(string s, char mx) {
    if ((int)s.length() == N) {
        cout << s << endl;
        return;
    }
    for (char c = 'a'; c <= mx + 1; c++) {
        dfs(s + c, max(mx, c));
    }
}

void solve() { dfs("a", 'a'); }

int main() {
    cin >> N;

    solve();

    return 0;
}
