/*
[abc114] D - 756
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

int N;

ll solve() {
    map<int, int> fac;
    for (int i = 1; i <= N; i++) {
        int n = i;
        for (int j = 2; j * j <= n; j++) {
            while (n % j == 0) {
                n /= j;
                fac[j]++;
            }
        }
        if (n > 1) {
            fac[n]++;
        }
    }

    map<int, int> cnt;
    for (auto& kv : fac) {
        for (int c : {3, 5, 15, 25, 75}) {
            if (kv.second >= c - 1) {
                cnt[c]++;
            }
        }
    }

    ll ans = 0;
    ans += cnt[75];
    ans += (cnt[3] - 1) * cnt[25];
    ans += (cnt[5] - 1) * cnt[15];
    ans += ((cnt[3] - 2) * cnt[5] * (cnt[5] - 1)) / 2;

    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
