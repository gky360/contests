// AtCoder Grand Contest 017
// C - Snuke and Spells

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


const int MAX_N = 200;
const int MAX_M = 200;

int N, M;
vector<int> A;
int dp[MAX_N + 1];
int cnt[MAX_N + 1];

int main() {

    int x, y;

    cin >> N >> M;
    A.reserve(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int q = 0; q < M; q++) {
        cin >> x >> y;
        A[x - 1] = y;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < N; i++) {
            cnt[A[i]]++;
        }

        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            dp[i] = N;
            for (int j = 0; j < i; j++) {
                dp[i] = min(dp[i], dp[j] + max(0, i - j - cnt[i]));
            }
        }

        cout << dp[N] << endl;
    }


    return 0;

}



