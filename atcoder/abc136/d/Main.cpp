/*
[abc136] D - Gathering Children
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
string S;
int ans[MAX_N];

void solve() {
    for (int i = 0, cnt = 0; i < N; i++) {
        if (S[i] == 'R') {
            cnt++;
        } else {
            ans[i] += cnt / 2;
            ans[i - 1] += (cnt + 1) / 2;
            cnt = 0;
        }
    }
    for (int i = N - 1, cnt = 0; i >= 0; i--) {
        if (S[i] == 'L') {
            cnt++;
        } else {
            ans[i] += cnt / 2;
            ans[i + 1] += (cnt + 1) / 2;
            cnt = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> S;
    N = S.length();

    solve();

    return 0;
}
