/*
[arc098] C - Attention
*/

#include <algorithm>
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

const int MAX_N = 300000;

int N;
string s;

int solve() {
    int sum[MAX_N + 1];
    sum[0] = 0;
    for (int i = 0; i < N; i++) {
        sum[i + 1] = sum[i] + (s[i] == 'W' ? 1 : 0);
    }

    int ans = N;
    for (int i = 1; i <= N; i++) {
        ans = min(ans, sum[i - 1] + N - i - (sum[N] - sum[i]));
    }
    return ans;
}

int main() {
    cin >> N;
    cin >> s;

    cout << solve() << endl;

    return 0;
}
