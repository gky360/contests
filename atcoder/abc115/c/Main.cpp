/*
[abc115] C - Christmas Eve
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

const int MAX_N = 1e5;
const int INF = 1e9 + 1;

int N, K;
int h[MAX_N];

int solve() {
    sort(h, h + N);
    int ans = INF;
    for (int i = 0; i + K - 1 < N; i++) {
        ans = min(ans, h[i + K - 1] - h[i]);
    }
    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    cout << solve() << endl;

    return 0;
}
