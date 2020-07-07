/*
[abc146] F - Sugoroku
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N, M;
string S;
vector<int> ans;

bool solve() {
    int m[MAX_N + 1];
    m[N] = N;
    for (int i = N - 1; i >= 0; i--) {
        m[i] = S[i] == '1' ? m[i + 1] : i;
    }

    int x;
    for (x = N; x > M; x = m[x - M]) {
        if (x <= m[x - M]) {
            return false;
        }
        ans.push_back(x - m[x - M]);
    }
    ans.push_back(x);

    reverse(ALL(ans));

    return true;
}

int main() {
    cin >> N >> M;
    cin >> S;

    if (!solve()) {
        cout << -1 << endl;
        return 0;
    }
    for (int n : ans) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
