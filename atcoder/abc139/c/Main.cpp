/*
[abc139] C - Lower
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int INF = 1e9 + 1;

int N;
int H[MAX_N + 1];

ll solve() {
    H[N] = INF;
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (H[i - 1] >= H[i]) {
            cnt++;
        } else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    cout << solve() << endl;

    return 0;
}
