// Typical DP Contest
// A - コンテスト

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100;
const int MAX_P = 100;

int N;
bool dp[MAX_P * MAX_N + 1];

int main() {

    int p;

    cin >> N;
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    for (int j = 0; j < N; j++) {
        cin >> p;
        for (int i = MAX_P * MAX_N; i >= p; i--) {
            dp[i] = dp[i] || dp[i - p];
        }
    }

    cout << count_if(dp, dp + MAX_P * MAX_N, [](bool tf) { return tf; }) << endl;

    return 0;

}
