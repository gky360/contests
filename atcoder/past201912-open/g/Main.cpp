/*
[past201912-open] G - 組分け / Division
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 10;
const int INF = 1e9;

int N;
int A[MAX_N][MAX_N];

int calc(int pat) {
    int g[MAX_N];
    for (int i = 0; i < N; i++) {
        g[i] = pat % 3;
        pat /= 3;
    }

    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (g[i] == g[j]) {
                ret += A[i][j];
            }
        }
    }

    return ret;
}

ll solve() {
    int pat = 1;
    for (int i = 0; i < N; i++) {
        pat *= 3;
    }

    int ans = -INF;
    for (; pat >= 0; pat--) {
        ans = max(ans, calc(pat));
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> A[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}
