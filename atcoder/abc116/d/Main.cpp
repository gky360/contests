/*
[abc116] D - Various Sushi
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

const int MAX_N = 1e5;

int N, K;
pli dt[MAX_N];
int cnt[MAX_N + 1];

ll solve() {
    sort(dt, dt + N, greater<pli>());

    ll s = 0, x = 0;
    for (int i = 0; i < K; i++) {
        s += dt[i].first;
        if (cnt[dt[i].second] == 0) {
            x++;
        }
        cnt[dt[i].second]++;
    }

    ll ans = s + x * x;
    int j = K - 1;
    for (int i = K; i < N; i++) {
        if (cnt[dt[i].second] > 0) {
            continue;
        }

        for (; j >= 0; j--) {
            if (cnt[dt[j].second] > 1) {
                break;
            }
        }
        if (j < 0) {
            break;
        }

        s += dt[i].first;
        s -= dt[j].first;
        cnt[dt[i].second]++;
        cnt[dt[j].second]--;
        j--;
        x++;

        ans = max(ans, s + x * x);
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> dt[i].second >> dt[i].first;
    }

    cout << solve() << endl;

    return 0;
}
