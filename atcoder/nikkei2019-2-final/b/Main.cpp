/*
[nikkei2019-2-final] B - NIKKEI String
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 500;

int N;
string S;
int c[MAX_N][MAX_N];

ll solve() {
    int N = S.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i] == S[j]) {
                c[i][j] = 1;
            }
        }
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - 2; j >= 0; j--) {
            if (c[i][j]) {
                c[i][j] += c[i + 1][j + 1];
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N && i + j < N; j++) {
            if (c[i][N - j] != j) continue;
            for (int k = 1; i + j + k + k < N - j; k++) {
                if (c[i + j][i + j + k] < k) continue;
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
