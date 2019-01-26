/*
[abc104] D - We Love ABC
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;
const ll MOD = 1e9 + 7;
const int K = 3;

string S;
int N;
ll dp[K + 1][MAX_N + 1];

ll solve() {
    dp[0][0] = 1;

    for (int k = 0; k <= K; k++) {
        for (int i = 1; i <= N; i++) {
            ll p = ((S[i - 1] == '?') ? 3 : 1) * dp[k][i - 1];
            ll q = (k > 0 && (S[i - 1] == ('A' + k - 1) || S[i - 1] == '?'))
                       ? dp[k - 1][i - 1]
                       : 0;
            dp[k][i] = (p + q) % MOD;
        }
    }

    return dp[K][N];
}

int main() {
    cin >> S;
    N = S.size();

    cout << solve() << endl;

    return 0;
}
