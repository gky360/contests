/*
[agc029] A - Irreversible operation
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

string S;

ll solve() {
    ll ans = 0;
    int cnt_b = 0;
    for (char c : S) {
        if (c == 'B') {
            cnt_b++;
        } else {
            ans += cnt_b;
        }
    }
    return ans;
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
