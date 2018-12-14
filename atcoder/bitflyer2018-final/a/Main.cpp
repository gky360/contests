/*
[bitflyer2018-final] A - 値札
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

const int MAX_N = 100;

int N;
int p[MAX_N];

int solve() {
    int ans = 9;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int a = p[i]; a % 10 == 0; a /= 10) {
            cnt++;
        }
        ans = min(ans, cnt);
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    cout << solve() << endl;

    return 0;
}
