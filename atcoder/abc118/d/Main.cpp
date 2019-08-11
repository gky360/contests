/*
[abc118] D - Match Matching
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int r[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

const int MAX_N = 1e4;

int N, M;
int A[10];
int dp[10][MAX_N + 10];

inline void chmax(int &a, int v) { a = max(a, v); }

string solve() {
    sort(A, A + M);

    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < M; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= N; j++) {
            if (i - 1 >= 0) {
                chmax(dp[i][j], dp[i - 1][j]);
            }
            if (j - r[A[i]] >= 0 && dp[i][j - r[A[i]]] >= 0) {
                chmax(dp[i][j], dp[i][j - r[A[i]]] + 1);
            }
        }
    }

    string ans;
    for (int i = M - 1, j = N; i >= 0 && j > 0;) {
        if (j - r[A[i]] >= 0 && dp[i][j - r[A[i]]] == dp[i][j] - 1) {
            j -= r[A[i]];
            ans.push_back('0' + A[i]);
        } else {
            i--;
        }
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
