// Typical dpr Contest
// D - サイコロ

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100;
const int MAX_D2 = 60 + 1;
const int MAX_D3 = 38 + 1;
const int MAX_D5 = 26 + 1;
const double ONE_SIXTH = 1.0 / 6.0;
const int dice[6][3] = {
    {0, 0, 0},
    {1, 0, 0},
    {0, 1, 0},
    {2, 0, 0},
    {0, 0, 1},
    {1, 1, 0},
};

int N;
ll D;
double dp[2][MAX_D2][MAX_D3][MAX_D5];

int main() {

    ll d;
    int d2c, d3c, d5c;
    double ans;

    cin >> N >> D;
    d = D;

    for (d2c = 0; d % 2 == 0; d /= 2) { d2c++; }
    for (d3c = 0; d % 3 == 0; d /= 3) { d3c++; }
    for (d5c = 0; d % 5 == 0; d /= 5) { d5c++; }

    if (d != 1) {
        cout << 0.0 << endl;
        return 0;
    }

    memset(dp[0], 0, sizeof(dp[0]));
    dp[0][0][0][0] = 1.0;

    for (int n = 0; n < N; n++) {
        memset(dp[(n + 1) % 2], 0, sizeof(dp[(n + 1) % 2]));
        for (int d2 = d2c; d2 >= 0; d2--) {
            for (int d3 = d3c; d3 >= 0; d3--) {
                for (int d5 = d5c; d5 >= 0; d5--) {
                    for (int k = 0; k < 6; k++) {
                        dp[(n + 1) % 2][min(d2c, d2 + dice[k][0])][min(d3c, d3 + dice[k][1])][min(d5c, d5 + dice[k][2])]
                            += ONE_SIXTH * dp[n % 2][d2][d3][d5];
                    }
                }
            }
        }
    }

    ans = dp[N % 2][d2c][d3c][d5c];
    cout << fixed << setprecision(10) << ans << endl;


    return 0;

}
