/*
[dp] K - Stones
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

const int MAX_N = 100;
const int MAX_K = 1e5;

int N, K;
int a[MAX_N];
bool dp[MAX_K + 1];

bool solve() {
    for (int i = 1; i <= K; i++) {
        dp[i] = false;
        for (int j = 0; j < N; j++) {
            if (i - a[j] >= 0 && !dp[i - a[j]]) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[K];
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << (solve() ? "First" : "Second") << endl;

    return 0;
}
