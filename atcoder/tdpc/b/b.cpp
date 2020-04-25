// Typical DP Contest
// B - ゲーム

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_A = 1000;
const int MAX_B = 1000;

int A, B;
int a[MAX_A + 1], b[MAX_B + 1];
int dp[MAX_A + 1][MAX_B + 1];

int main() {

    cin >> A >> B;
    for (int i = 0; i < A; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < B; j++) {
        cin >> b[j];
    }

    dp[A][B] = 0;
    for (int i = A - 1; i >= 0; i--) {
        dp[i][B] = dp[i + 1][B] + a[i] * ((i + 1 + B) % 2);
    }
    for (int j = B - 1; j >= 0; j--) {
        dp[A][j] = dp[A][j + 1] + b[j] * ((j + 1 + A) % 2);
    }

    for (int i = A - 1; i >= 0; i--) {
        for (int j = B - 1; j >= 0; j--) {
            if ((i + j) % 2 == 0) {
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j + 1] + b[j]);
            } else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    cout << dp[0][0] << endl;

    return 0;

}
