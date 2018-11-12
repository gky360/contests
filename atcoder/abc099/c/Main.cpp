/*
[abc099] C - Strange Bank
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

int N;

int solve() {
    int ans = N;
    for (int t = 0; t <= N; t++) {
        int cnt = 0;
        for (int i = t; i > 0; i /= 6) {
            cnt += i % 6;
        }
        for (int i = N - t; i > 0; i /= 9) {
            cnt += i % 9;
        }
        ans = min(ans, cnt);
    }
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
