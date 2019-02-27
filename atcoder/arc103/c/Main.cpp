/*
[arc103] C - /\/\/\/
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
const int MAX_V = 100000;

int N;
int v[MAX_N];
pii cnt[2][MAX_V + 1];

ll solve() {
    for (int i = 0; i < N; i++) {
        cnt[i % 2][v[i]].first++;
    }
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i <= MAX_V; i++) {
            cnt[k][i].second = i;
        }
        sort(cnt[k], cnt[k] + MAX_V + 1, greater<pii>());
    }

    int ans[2] = {N / 2 - cnt[0][0].first, N / 2 - cnt[1][0].first};
    if (cnt[0][0].second == cnt[1][0].second) {
        int k = (cnt[0][0].first - cnt[0][1].first <=
                 cnt[1][0].first - cnt[1][1].first)
                    ? 0
                    : 1;
        ans[k] += cnt[k][0].first - cnt[k][1].first;
    }

    return ans[0] + ans[1];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    cout << solve() << endl;

    return 0;
}
