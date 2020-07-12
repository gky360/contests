/*
[sumitrust2019] D - Lucky PIN
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 30000;

int N;
string S;
int cnt[10][MAX_N + 1];

bool can(int n) {
    int x = 0;
    for (int i = 0; i < 3; i++) {
        int j = n % 10;
        n /= 10;
        x = lower_bound(cnt[j], cnt[j] + N + 1, cnt[j][x] + 1) - cnt[j];
        if (x >= N + 1) {
            return false;
        }
    }
    return true;
}

ll solve() {
    for (int i = 1; i <= N; i++) {
        cnt[S[i - 1] - '0'][i]++;
    }
    for (int j = 0; j < 10; j++) {
        for (int i = 1; i <= N; i++) {
            cnt[j][i] += cnt[j][i - 1];
        }
    }

    int ans = 0;
    for (int n = 0; n < 1000; n++) {
        if (can(n)) {
            ans++;
        }
    }
    return ans;
}

int main() {
    cin >> N;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
