/*
[abc128] D - equeue
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
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
typedef pair<ll, ll> pll;

const int MAX_N = 50;
const int INF = 1e9;

int N, K;
int V[MAX_N];

ll solve() {
    ll ans = -INF;
    for (int p = 0; p <= N; p++) {
        for (int q = 0; p + q <= N; q++) {
            for (int r = 0; r <= min(K - p - q, p + q); r++) {
                vector<int> d;
                for (int i = 0; i < p; i++) {
                    d.push_back(V[i]);
                }
                for (int i = N - 1; i >= N - q; i--) {
                    d.push_back(V[i]);
                }
                sort(d.begin(), d.end());

                ll s = 0;
                for (int i = r; i < (int)d.size(); i++) {
                    s += d[i];
                }
                ans = max(ans, s);
            }
        }
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    cout << solve() << endl;

    return 0;
}
