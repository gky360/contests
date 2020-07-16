/*
[abc147] C - HonestOrUnkind2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 15;

int N;
int A[MAX_N];
int x[MAX_N][MAX_N], y[MAX_N][MAX_N];

bool can(int pat) {
    for (int i = 0; i < N; i++) {
        if ((pat >> i) & 1) {
            for (int j = 0; j < A[i]; j++) {
                if (((pat >> x[i][j]) & 1) != y[i][j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

ll solve() {
    int ans = 0;
    for (int pat = 0; pat < (1 << N); pat++) {
        if (can(pat)) {
            int cnt = 0;
            for (int p = pat; p > 0; p >>= 1) {
                if (p & 1) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        for (int j = 0; j < A[i]; j++) {
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }

    cout << solve() << endl;

    return 0;
}
