/*
[abc106] B - 105
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
    int ans = 0;
    for (int n = 1; n <= N; n += 2) {
        int cnt = 0;
        for (int d = 1; d <= N; d++) {
            if (n % d == 0) {
                cnt++;
            }
        }
        if (cnt == 8) {
            ans++;
        }
    }
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
