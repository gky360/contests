/*
[abc148] D - Brick Break
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 200000;

int N;
int a[MAX_N];
bool has[MAX_N + 1];

ll solve() {
    int len = 0;

    has[0] = true;
    for (int i = 0; i < N; i++) {
        if (has[a[i] - 1]) {
            len = max(len, a[i]);
            has[a[i]] = true;
        }
    }

    int ans = (len == 0) ? -1 : N - len;

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
