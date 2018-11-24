/*
[abc100] D - Patisserie ABC
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

const int MAX_N = 1000;
const int K = 3;

int N, M;
ll x[MAX_N][K];

ll solve() {
    ll ans = 0;
    for (int pat = 0; pat < (1 << K); pat++) {
        vector<ll> v;
        for (int i = 0; i < N; i++) {
            ll s = 0;
            for (int k = 0; k < K; k++) {
                s += (((pat >> k) & 1) ? 1LL : -1LL) * x[i][k];
            }
            v.push_back(s);
        }
        sort(v.rbegin(), v.rend());
        ll sum = 0;
        for (int i = 0; i < M; i++) {
            sum += v[i];
        }
        ans = max(ans, sum);
    }
    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < K; k++) {
            cin >> x[i][k];
        }
    }

    cout << solve() << endl;

    return 0;
}
