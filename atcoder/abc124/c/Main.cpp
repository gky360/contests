/*
[abc124] C - Coloring Colorfully
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

string S;

ll solve() {
    int ans = S.length();
    for (int p = 0; p < 2; p++) {
        int cnt = 0;
        for (int i = 0; i < (int)S.length(); i++) {
            cnt += ((S[i] - '0') ^ i ^ p) & 1;
        }
        ans = min(ans, cnt);
    }

    return ans;
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
