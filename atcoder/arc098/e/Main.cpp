/*
[arc098] E - Range Minimum Queries
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

const int MAX_N = 2000;
const int INF = 1e9 + 1;

int N, K, Q;
int a[MAX_N + 1];

int solve() {
    int ans = INF;
    for (int yi = 0; yi < N; yi++) {
        int y = a[yi];
        int pre_i = -1;
        vector<int> cs;
        for (int i = 0; i <= N; i++) {
            if (a[i] >= y) {
                continue;
            }
            vector<int> c(a + pre_i + 1, a + i);
            pre_i = i;
            if ((int)c.size() >= K) {
                sort(c.begin(), c.end());
                cs.insert(cs.end(), c.begin(), c.end() - K + 1);
            }
        }
        if ((int)cs.size() < Q) {
            continue;
        }
        sort(cs.begin(), cs.end());
        ans = min(ans, cs[Q - 1] - y);
    }
    return ans;
}

int main() {
    cin >> N >> K >> Q;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    a[N] = -1;

    cout << solve() << endl;

    return 0;
}
