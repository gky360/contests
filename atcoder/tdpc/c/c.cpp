// Typical dpr Contest
// C - トーナメント

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_K = 10;
const int MAX_N = (1 << MAX_K);
const double EPS = 1e-9;

int K, N;
int R[MAX_N];
double dp[MAX_K + 1][MAX_N];

double p(int rl, int rr) {
    return 1.0 / (1.0 + pow(10.0, (double)(rr - rl) / 400.0));
}

int main() {

    int l, r;

    cin >> K;
    N = (1 << K);
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }

    fill(dp[0], dp[0] + N, 1);
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < N; i++) {
            l = (i ^ (1 << k)) / (1 << k) * (1 << k);
            r = l + (1 << k);
            dp[k + 1][i] = 0.0;
            for (int j = l; j < r; j++) {
                dp[k + 1][i] += dp[k][j] * p(R[i], R[j]);
            }
            dp[k + 1][i] *= dp[k][i];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << fixed << setprecision(9) << dp[K][i] << endl;
    }


    return 0;

}
